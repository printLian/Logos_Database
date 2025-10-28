#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(5, 0);
  lcd.print("My name is");

  lcd.setCursor(2, 1);
  lcd.print("Joseph Arenas");

  delay(1000); // short pause before starting animation
}

void loop() {}
 /*   // Scroll text to the right
  lcd.scrollDisplayRight();
  delay(300);
}

  // Scroll text to the left
 /* lcd.scrollDisplayLeft();
  delay(300);

  // Blink effect
  lcd.blink();
  delay(500);
  lcd.noBlink();
  delay(500);
}*/
