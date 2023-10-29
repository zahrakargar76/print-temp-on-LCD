#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int Red=10, Green=9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float data = analogRead(A0);
  float Temp = data * 0.48828125;
  Serial.print("Temp: ");
  Serial.println(Temp);
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(Temp);
  if(Temp > 28){
    lcd.setCursor(0,1);
    lcd.print("Warm");
    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);
  }
   if(Temp <27){
    lcd.setCursor(0,1);
    lcd.print("Cool");
    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
  }
}
