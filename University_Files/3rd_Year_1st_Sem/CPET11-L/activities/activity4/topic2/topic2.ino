#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
DS1302 rtc(2, 3, 4);

void setup() {
  lcd.init();
  lcd.backlight();

  rtc.writeProtect(false); 
  rtc.halt(false);         

  // Time t(2025, 10, 23, 5, 00, 0, Time::kSunday);
  // rtc.time(t);
}

void loop() {
  Time t = rtc.time();
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

  delay(1000);
}

/*
SDA and SCL to SDA and SCL

rst, data and clk= 2, 3, 4
*/