#include <Servo.h>
Servo myservo;
Servo myservo2;

int thresholdValue = 150;

byte motor1Pin1 = 8;
byte motor1Pin2 = 9;
byte motor2Pin1 = 10;
byte motor2Pin2 = 11;

byte ldrPin1 = A0;
byte ldrPin2 = A1;

int pvalue1 = 0;
int pvalue2 = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  myservo.attach(6);
  myservo2.attach(7);
  myservo.write(0);
  myservo2.write(0);
}


void loop() {
  int ldrValue1 = analogRead(ldrPin1);
  int ldrValue2 = analogRead(ldrPin2);
  Serial.println("ldr1");
  Serial.println(ldrValue1);
  Serial.println("ldr2");
  Serial.println(ldrValue2);
  if (ldrValue1 < thresholdValue)
  {
    myservo.write(90);
    myservo2.write(90);
    delay(1000);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(5300);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    delay(2000);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);


  }
  else if (ldrValue2 < thresholdValue)
  {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    delay(1300);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(2700);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    delay(5000);
    myservo.write(0);
    myservo2.write(0);
  }
}
