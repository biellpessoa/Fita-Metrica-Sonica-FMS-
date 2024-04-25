int PinoPulso = 13;
int PinoRetorno = 10;

float leituraSensor(int PinoPulso, int PinoRetorno) {
  pinMode(PinoPulso, OUTPUT);
  digitalWrite(PinoPulso, LOW);
  delayMicroseconds(2);
  digitalWrite(PinoPulso, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinoPulso, LOW);
  pinMode(PinoRetorno, INPUT);
  return (pulseIn(PinoRetorno, HIGH)* 0.01723);
}
#include <LiquidCrystal.h>
float cm = 0;
float metro = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Trena digital");
  delay(1500);
  lcd.setCursor(0, 1);
  pinMode(7, INPUT);
}

void loop() {
  lcd.clear();
  cm = leituraSensor(13, 10);
  metro = (cm / 100);
  lcd.setCursor(0, 0);
  lcd.print("cm: ");
  lcd.setCursor(4,0);
  lcd.print(cm);
  lcd.setCursor(0,1);
  lcd.print("metro: ");
  lcd.setCursor(7,1);
  lcd.print(metro);
  delay(1000);
}
