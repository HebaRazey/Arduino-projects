#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int tempPin = A3;
int gasPin = A0;
int fanPin = 9;
int ledPin = 8;

float lastTemp = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);

  pinMode(fanPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  delay(10000); // MQ-2 warm-up
}

void loop() {

  // ===== LM35 =====
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1024.0);

  float temperature = voltage * 100;

  // smoothing
  temperature = (temperature + lastTemp) / 2;
  lastTemp = temperature;

  // ===== MQ-2 =====
  int gasValue = analogRead(gasPin);

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C | Gas: ");
  Serial.println(gasValue);

  int fanSpeed = 0;
  String fanStatus = "OFF";

  // ===== GAS OVERRIDE =====
  if (gasValue > 300) {

    fanSpeed = 255;
    fanStatus = "GAS!";

    digitalWrite(ledPin, HIGH);
  }
  else {

    digitalWrite(ledPin, LOW);

    // ===== TEMPERATURE CONTROL =====
    if (temperature < 41) {

      fanSpeed = 0;
      fanStatus = "OFF";
    }
    else if (temperature >= 41.5) {

      fanSpeed = 255;
      fanStatus = "HIGH";
    }
    else {

      fanSpeed = 200;
      fanStatus = "MED";

      // kick-start
      analogWrite(fanPin, 255);
      delay(300);
    }
  }

  analogWrite(fanPin, fanSpeed);

  // ===== LCD DISPLAY =====

  // Clear line 1
  lcd.setCursor(0, 0);
  lcd.print("                ");

  // Temp and Gas side by side
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);

  lcd.setCursor(9, 0);
  lcd.print("G:");
  lcd.print(gasValue);

  // Clear line 2
  lcd.setCursor(0, 1);
  lcd.print("                ");

  // Fan status below
  lcd.setCursor(0, 1);
  lcd.print("Fan:");
  lcd.print(fanStatus);

  delay(1000);
}
