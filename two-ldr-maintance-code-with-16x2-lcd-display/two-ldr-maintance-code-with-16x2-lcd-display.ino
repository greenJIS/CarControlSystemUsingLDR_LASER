#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int thresholdValue = 500;

byte ldrPin1 = A0;
byte ldrPin2 = A1;

int count = 0;

int priviousValue1 = 0;
int priviousValue2 = 0;

bool ldrCheck(int ldrValue){
  if (ldrValue>=thresholdValue) return true;
  else return false;
}

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrValue1 = analogRead(ldrPin1);
  int ldrValue2 = analogRead(ldrPin2);
  
  if(ldrCheck(ldrValue1) != ldrCheck(priviousValue1)) count++;
  if(ldrCheck(ldrValue2) != ldrCheck(priviousValue2)) count--;
  
  //Serial.println(count);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("WC To CAR contrl");
  lcd.print("Total Car:  ");
  lcd.println(count/2);
  delay(10);
  
  priviousValue1 = ldrValue1;
  priviousValue2 = ldrValue2;
}
