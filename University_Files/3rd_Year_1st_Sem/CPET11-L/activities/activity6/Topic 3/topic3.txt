// Blynk credentials (MUST be before includes)
#define BLYNK_TEMPLATE_ID "TMPL618GSH8_F"
#define BLYNK_TEMPLATE_NAME "Plant watering system"
#define BLYNK_AUTH_TOKEN "EmG3-yCYv8iLg-TqsDeS755HlW6ZJuz5"

//Include the library files
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define sensor 33   // Soil moisture sensor pin
#define relay 4     // Relay pin for water pump

//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;

// Use token from #define
char auth[] = BLYNK_AUTH_TOKEN;

//Enter your WIFI SSID and password
char ssid[] = "1234";
char pass[] = "hello123";

void setup() {
// Debug console
Serial.begin(115200);

// Connect to Blynk cloud
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

// Setup LCD
lcd.init();
lcd.backlight();

// Relay setup
pinMode(relay, OUTPUT);
digitalWrite(relay, HIGH); // OFF by default

// Boot animation
lcd.setCursor(1, 0);
lcd.print("System Loading");
for (int a = 0; a <= 15; a++) {
lcd.setCursor(a, 1);
lcd.print(".");
delay(150);
}
lcd.clear();

// Run soilMoisture() every 1 second
timer.setInterval(1000L, soilMoisture);
}

// Function to read soil moisture sensor
void soilMoisture() {
int value = analogRead(sensor);
value = map(value, 0, 4095, 0, 100);   // Convert raw to percentage
value = (value - 100) * -1;            // Invert so dry = low %

// Send to Blynk app
Blynk.virtualWrite(V0, value);

// Debug print
Serial.print("Soil Moisture: ");
Serial.print(value);
Serial.println("%");

// Show on LCD
lcd.setCursor(0, 0);
lcd.print("Moisture: ");
lcd.print(value);
lcd.print("%   ");
}

// Function to control motor from app button (V1)
BLYNK_WRITE(V1) {
bool Relay = param.asInt();
if (Relay == 1) {
digitalWrite(relay, LOW);   // Turn ON motor
lcd.setCursor(0, 1);
lcd.print("Motor is ON  ");
} else {
digitalWrite(relay, HIGH);  // Turn OFF motor
lcd.setCursor(0, 1);
lcd.print("Motor is OFF ");
}
}

void loop() {
Blynk.run();   // Run Blynk
timer.run();   // Run timer tasks
}