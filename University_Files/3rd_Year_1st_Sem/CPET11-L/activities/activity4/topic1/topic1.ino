#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int buzzer = 6;
int buttons[]= {2, 3, 4, 5};

int minutes = 12;
int seconds = 0;
boolean running = false;
unsigned long prevMillis = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  for(int i = 0 ; i < 4 ; i++){
    pinMode(buttons[i], OUTPUT);
  } 
  displayTime();
}

void loop() {
  if (digitalRead(buttons[0]) == HIGH) {
    running = true;
    delay(200);
  }
  if (digitalRead(buttons[1]) == HIGH) {
    running = false;
    minutes = 12;
    seconds = 0;
    digitalWrite(buzzer, LOW);
    displayTime();
    delay(200);
  }
  if (digitalRead(buttons[2]) == HIGH && !running) {
    if (minutes > 0 || seconds >= 10) {
      if (seconds >= 10) {
        seconds -= 10;
      } else if (minutes > 0) {
        minutes--;
        seconds = 50;
      }
    }
    displayTime();
    delay(200);
  }
  if (digitalRead(buttons[3]) == HIGH && !running) {
    if (seconds <= 49) {
      seconds += 10;
    } else {
      if (minutes < 99) {
        minutes++;
        seconds = 0;
      }
    }
    displayTime();
    delay(200);
  }

  if (running) {
    unsigned long currentMillis = millis();
    if (currentMillis - prevMillis >= 1000) {
      prevMillis = currentMillis;
      if (seconds == 0) {
        if (minutes == 0) {
          running = false;
          digitalWrite(buzzer, HIGH);
        } else {
          minutes--;
          seconds = 59;
        }
      } else {
        seconds--;
      }
      displayTime();
    }
  }
}

void displayTime() {
  lcd.clear();
  lcd.setCursor(4, 1);
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}

/*
SDA and SCL to SDA and SCL

Button 1,2,3,4 to 2,3,4,5
Pull up external resistor to ground 10k ohms. Connect button pins to pull up resistor.
Buzzer=6
*/