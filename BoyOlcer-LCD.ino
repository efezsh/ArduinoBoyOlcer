#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

int echo = 12;
int trig = 13;
float sure, mesafe;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = sure * 0.03432 / 2;
  lcd.setCursor(6, 0);
  lcd.print("Boy:");
  if (mesafe >= 199 && mesafe <= 201) {
    lcd.setCursor(2, 1);
    lcd.print("Dogru Mesafe");
  } else if (200-mesafe > 0 && 200-mesafe < 201) {
    if (200-mesafe > 99) {
      lcd.setCursor(5, 1);
      lcd.print(200-int(mesafe));
      lcd.setCursor(8, 1);
      lcd.print("cm");
    } else if (200-mesafe < 100) {
      lcd.setCursor(6, 1);
      lcd.print(200-int(mesafe));
      lcd.setCursor(8, 1);
      lcd.print("cm");
    }
  } else if (200-mesafe < 0) {
    lcd.setCursor(6,2);
    lcd.print("Hata");
  }
  delay(5000);
  lcd.clear();
}