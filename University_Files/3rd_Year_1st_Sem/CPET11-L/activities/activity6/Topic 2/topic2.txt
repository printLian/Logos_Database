// Blynk 2.0 Setup
#define BLYNK_TEMPLATE_ID "TMPL6fkO4INWC"
#define BLYNK_TEMPLATE_NAME "GAS level monitoring system"
#define BLYNK_AUTH_TOKEN "GO27ivSmIl6l_KydsKM46MrCIgforkX3"

//Include the library files
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define sensor 34
#define buzzer 13

//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;

//Enter your WIFI SSID and password
char ssid[] = "1234";
char pass[] = "hello123";

WidgetLED LED(V1); // Declare globally instead of inside the function

void setup() {
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(1, 0);
  lcd.print("System Loading");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(200);
  }
  lcd.clear();

  timer.setInterval(1000L, GASLevel); // Run GASLevel every 1 sec
}

//Get the gas sensor values
void GASLevel() {
  int value = analogRead(sensor);
  value = map(value, 0, 4095, 0, 100);

  if (value >= 50) {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Warning!  ");
    LED.on();
  } else {
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Normal   ");
    LED.off();
  }

  Blynk.virtualWrite(V0, value);
  Serial.println(value);
  lcd.setCursor(0, 0);
  lcd.print("GAS Level :");
  lcd.print(value);
  lcd.print("   "); // Spaces to overwrite old digits
}

void loop() {
  Blynk.run();   // Run the Blynk library
  timer.run();   // Run the timer
}