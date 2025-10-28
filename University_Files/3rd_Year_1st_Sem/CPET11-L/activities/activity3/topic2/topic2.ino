// =======================================================
// Arduino Mega 2560: LM35 Temperature Display
// LCD 16x2 Display (I2C or 4-bit Parallel)
// Displays temperature in Celsius and Kelvin
// =======================================================

// === SELECT LCD TYPE ===
// Set to 1 if using I2C LCD backpack, 0 if using 4-bit parallel
#define USE_I2C 1

// === Include libraries ===
#if USE_I2C
  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 20, 4); // Change address if needed (0x27 or 0x3F)
#else
  #include <LiquidCrystal.h>
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, EN, D4, D5, D6, D7
#endif

// === LM35 Settings ===
#define LM35_PIN A1  // LM35 OUT pin connected to analog pin A0

void setup() {
  // Start serial monitor (optional)
  Serial.begin(9600);
  analogReference(INTERNAL1V1);

  // Initialize LCD
#if USE_I2C
  lcd.init();
  lcd.backlight();
#else
  lcd.begin(20, 4);
#endif

  // Startup message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LM35 Temp Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // === Read LM35 Sensor ===
  int rawValue = analogRead(LM35_PIN);

  // LM35 formula: 10mV per °C
  // Temp(°C) = (ADC * 500) / 1023
  float celsius = (rawValue * 110.0) / 1023.0;  // 1.1 V = 110 °C max;
  float kelvin = celsius + 273.15;

  // === Display on LCD ===
  lcd.setCursor(0, 0);
  lcd.print("Cel: ");
  lcd.print(celsius, 1);   // 1 decimal place
  lcd.print((char)223);    // Degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("kel: ");
  lcd.print(kelvin, 2);
  lcd.print((char)223);    // 2 decimal places
  lcd.print("K");

  // === Print to Serial Monitor (optional) ===
  Serial.print("Temp: ");
  Serial.print(celsius, 1);
  Serial.print(" °C | ");
  Serial.print(kelvin, 2);
  Serial.println(" °K");

  delay(1000); // Update every 1 second
}

/*
Flat face to me
Vcc A1 GND
*/