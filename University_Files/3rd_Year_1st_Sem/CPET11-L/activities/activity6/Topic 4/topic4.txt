/*************************************************************
   Unified ESP32 Smart Monitor
   - Water Level
   - Gas Leak Detection
   - Plant Watering
   Using 16x2 LCD + Blynk 2.0
*************************************************************/

// ==== BLYNK PROJECT INFO ====
// Replace with YOUR credentials
#define BLYNK_TEMPLATE_ID "TMPL6zbi2xukB"
#define BLYNK_TEMPLATE_NAME "Activity6Topic4"
#define BLYNK_AUTH_TOKEN "3ySQjbx_EHKsG5DgEKsaJyHSs1hZmnkd"

char ssid[] = "1234";
char pass[] = "hello1234";

// ==== LIBRARIES ====
#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
BlynkTimer timer;

// ==== LCD ====
LiquidCrystal_I2C lcd(0x27, 20, 4);

// ==== PINS ====
// Water level sensor (Ultrasonic)
#define TRIGPIN  5
#define ECHOPIN  18

// Gas sensor
#define GAS_PIN  34

// Shared buzzer + warning LED
#define BUZZER   13
#define WARN_LED 27

// Soil Moisture + Pump
#define SOIL_PIN 35
#define PUMP_PIN 4

// ==== Tank Setup ====
int emptyTankDistance = 70;  // cm (empty)
int fullTankDistance  = 30;  // cm (full)

// ==== Variables ====
float distance;
int waterLevelPer;
int gasLevel;
int soilMoist;
int lcdPage = 0;   // To cycle LCD pages
bool buzzerState = false;

// ==== Blynk V-pins ====
#define VPIN_WATER   V1
#define VPIN_DIST    V2
#define VPIN_GAS     V3
#define VPIN_WARNLED V4
#define VPIN_SOIL    V5
#define VPIN_PUMP    V6

// ==================== FUNCTIONS ====================

// Measure distance from ultrasonic
float getDistance() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGPIN, LOW);
  long duration = pulseIn(ECHOPIN, HIGH, 30000);
  float d = ((duration / 2.0) * 0.0343);
  return d; // cm
}

// Water level monitoring
void waterLevelCheck() {
  distance = getDistance();
  if (distance > 3 && distance < 400) {
    waterLevelPer = map((int)distance, emptyTankDistance, fullTankDistance, 0, 100);
    if (waterLevelPer > 100) waterLevelPer = 100;
    if (waterLevelPer < 0) waterLevelPer = 0;

    Blynk.virtualWrite(VPIN_WATER, waterLevelPer);
    Blynk.virtualWrite(VPIN_DIST, distance);
  }
}

// Gas monitoring
void gasCheck() {
  gasLevel = analogRead(GAS_PIN);
  gasLevel = map(gasLevel, 0, 4095, 0, 100);
  Blynk.virtualWrite(VPIN_GAS, gasLevel);
}

// Soil moisture monitoring
void soilCheck() {
  soilMoist = analogRead(SOIL_PIN);
  soilMoist = map(soilMoist, 0, 4095, 100, 0); // Invert
  Blynk.virtualWrite(VPIN_SOIL, soilMoist);
}

// Pump control from Blynk
BLYNK_WRITE(VPIN_PUMP) {
  int state = param.asInt();
  if (state == 1) {
    digitalWrite(PUMP_PIN, LOW); // Relay ON
  } else {
    digitalWrite(PUMP_PIN, HIGH); // Relay OFF
  }
}

// Shared buzzer + warning LED logic
void warningCheck() {
  bool waterAlert = (waterLevelPer >= 90);
  bool gasAlert   = (gasLevel >= 90);

  if (waterAlert || gasAlert) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(WARN_LED, HIGH);
    Blynk.virtualWrite(VPIN_WARNLED, 1);
  } else {
    digitalWrite(BUZZER, LOW);
    digitalWrite(WARN_LED, LOW);
    Blynk.virtualWrite(VPIN_WARNLED, 0);
  }
}

// LCD Display Cycling
void lcdDisplay() {
  lcd.clear();
  if (lcdPage == 0) {
    lcd.setCursor(0, 0); lcd.print("Water: ");
    lcd.print(waterLevelPer); lcd.print("%");
    lcd.setCursor(0, 1); lcd.print("Dist: ");
    lcd.print(distance); lcd.print("cm");
  }
  else if (lcdPage == 1) {
    lcd.setCursor(0, 0); lcd.print("Gas Level: ");
    lcd.print(gasLevel); lcd.print("%");
    lcd.setCursor(0, 1);
    if (gasLevel >= 90) lcd.print("Warning!!!");
    else lcd.print("Normal");
  }
  else if (lcdPage == 2) {
    lcd.setCursor(0, 0); lcd.print("Soil: ");
    lcd.print(soilMoist); lcd.print("%");
    lcd.setCursor(0, 1); lcd.print("Pump: ");
    if (digitalRead(PUMP_PIN) == LOW) lcd.print("ON ");
    else lcd.print("OFF");
  }
  lcdPage = (lcdPage + 1) % 3; // Next page
}

// ==================== SETUP ====================
void setup() {
  Serial.begin(115200);

  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(GAS_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(WARN_LED, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); lcd.print("Smart Monitor");
  lcd.setCursor(0, 1); lcd.print("Starting...");
  delay(2000);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);

  // Timers
  timer.setInterval(2000L, waterLevelCheck);
  timer.setInterval(2000L, gasCheck);
  timer.setInterval(2000L, soilCheck);
  timer.setInterval(2000L, warningCheck);
  timer.setInterval(3000L, lcdDisplay);
}

// ==================== LOOP ====================
void loop() {
  Blynk.run();
  timer.run();
}
