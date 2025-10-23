#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
DS1302 rtc(2, 3, 4);

const int btnHour = 5;
const int btnMin  = 6;
const int relayPin = 7;
const int ledPin   = 8;

int alarmHour = 0;
int alarmMin = 0;
bool alarmTriggered = false;
unsigned long alarmStart = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  rtc.writeProtect(false); 
  rtc.halt(false);        

  // Time t(2025, 10, 23, 5, 00, 0, Time::kThursday);
  // rtc.time(t);

  pinMode(btnHour, INPUT);
  pinMode(btnMin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Alarm Clock Ready");
  delay(2000);
}

void loop() {
  Time t = rtc.time();
  if (digitalRead(btnHour) == HIGH) {
    alarmHour = (alarmHour + 1) % 24;
    delay(200); 
  }

  if (digitalRead(btnMin) == HIGH) {
    alarmMin = (alarmMin + 1) % 60;
    delay(200); 
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(t.yr);
  lcd.print("/");
  if (t.mon < 10) lcd.print("0");
  lcd.print(t.mon);
  lcd.print("/");
  if (t.date < 10) lcd.print("0");
  lcd.print(t.date);

  lcd.setCursor(0, 1);
  if (t.hr < 10) lcd.print("0");
  lcd.print(t.hr);
  lcd.print(":");
  if (t.min < 10) lcd.print("0");
  lcd.print(t.min);
  lcd.print(":");
  if (t.sec < 10) lcd.print("0");
  lcd.print(t.sec);

  lcd.setCursor(0, 2);
  lcd.print("Alarm: ");
  if (alarmHour < 10) lcd.print("0");
  lcd.print(alarmHour);
  lcd.print(":");
  if (alarmMin < 10) lcd.print("0");
  lcd.print(alarmMin);

  if (!alarmTriggered && t.hr == alarmHour && t.min == alarmMin && t.sec == 0) {
    alarmTriggered = true;
    alarmStart = millis();
    digitalWrite(relayPin, HIGH); 
  }

  if (alarmTriggered && (millis() - alarmStart >= 5000)) {
    digitalWrite(relayPin, LOW);  
    digitalWrite(ledPin, HIGH);   
  }

  delay(200); 
}

/*
SDA to SCL = SDA and SCL

rst, data clk = 2, 3, 4

button 1= 5
button 2= 6
external resistors 

Relay= 7
Common= VCC
Buzzer= NC
Red LED= NO
*/