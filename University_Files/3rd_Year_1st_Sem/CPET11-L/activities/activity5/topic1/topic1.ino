#include <Arduino.h>
#include <WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"
#include "soc/soc.h"           // Add this
#include "soc/rtc_cntl_reg.h"

// ====== WiFi & Sinric Pro Credentials ======
#define WIFI_SSID     "PLDTSATLINK7MSdh"
#define WIFI_PASS     "NetworkPolice1234!"
#define APP_KEY       "6e41d7c9-a153-49f5-9b1e-5e26b27c31eb"
#define APP_SECRET    "4a01b0b8-62aa-4706-8458-e7614c87f710-8d9d90df-ca7b-410b-96e5-dacefc1a21cd"

// Sinric Device IDs (create 2 Switch devices in SinricPro)
#define DEVICE_ID_1   "68d438dd51811ad2b7504752" 
#define DEVICE_ID_2   "68d4394451811ad2b75047d7"

// ====== Pin Definitions ======
#define RELAY1_PIN 23
#define RELAY2_PIN 22
#define BUTTON1_PIN 13
#define BUTTON2_PIN 12
#define LED1_PIN   21
#define LED2_PIN   19

#define DEBOUNCE_TIME 250
#define BAUD_RATE 9600

// Track button states for debounce
bool lastBtn1 = HIGH, lastBtn2 = HIGH;
unsigned long lastTime1 = 0, lastTime2 = 0;

// ====== Helper Functions ======
void setRelay(int relayPin, int ledPin, bool state) {
  digitalWrite(relayPin, state ? LOW : HIGH);   // Relay active LOW
  digitalWrite(ledPin, state ? HIGH : LOW);     // LED follows ON/OFF
}

// ====== Sinric Callbacks ======
bool onPowerState1(const String &deviceId, bool &state) {
  Serial.printf("[Sinric] Device1 -> %s\n", state ? "ON" : "OFF");
  setRelay(RELAY1_PIN, LED1_PIN, state);
  return true;
}

bool onPowerState2(const String &deviceId, bool &state) {
  Serial.printf("[Sinric] Device2 -> %s\n", state ? "ON" : "OFF");
  setRelay(RELAY2_PIN, LED2_PIN, state);
  return true;
}

// ====== Setup ======
void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); // Disable brownout - ADD AS FIRST LINE
  
  Serial.begin(BAUD_RATE);
  delay(1000);
  
  pinMode(RELAY1_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);

  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  // default OFF
  setRelay(RELAY1_PIN, LED1_PIN, false);
  setRelay(RELAY2_PIN, LED2_PIN, false);

  // WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nWiFi connected: ");
  Serial.println(WiFi.localIP());

  // Sinric Pro
  SinricProSwitch &switch1 = SinricPro[DEVICE_ID_1];
  SinricProSwitch &switch2 = SinricPro[DEVICE_ID_2];
  switch1.onPowerState(onPowerState1);
  switch2.onPowerState(onPowerState2);

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

// ====== Loop ======
void loop() {
  SinricPro.handle();
  unsigned long now = millis();

  // --- Button 1 ---
  bool btn1 = digitalRead(BUTTON1_PIN);
  if (btn1 != lastBtn1 && now - lastTime1 > DEBOUNCE_TIME) {
    lastTime1 = now;
    if (btn1 == LOW) { // Pressed
      bool currentState = (digitalRead(RELAY1_PIN) == LOW);
      setRelay(RELAY1_PIN, LED1_PIN, !currentState);
      SinricProSwitch &sw1 = SinricPro[DEVICE_ID_1];
      sw1.sendPowerStateEvent(!currentState);
    }
    lastBtn1 = btn1;
  }

  // --- Button 2 ---
  bool btn2 = digitalRead(BUTTON2_PIN);
  if (btn2 != lastBtn2 && now - lastTime2 > DEBOUNCE_TIME) {
    lastTime2 = now;
    if (btn2 == LOW) {
      bool currentState = (digitalRead(RELAY2_PIN) == LOW);
      setRelay(RELAY2_PIN, LED2_PIN, !currentState);
      SinricProSwitch &sw2 = SinricPro[DEVICE_ID_2];
      sw2.sendPowerStateEvent(!currentState);
    }
    lastBtn2 = btn2;
  }
}

/*
Push button1= 12
Push button2= 13
No pull up external resistor.
do it esp32 devkit v1 module

LEDS to NC
Common to VCC
1n1 and 1n2= 22 and 23
*/