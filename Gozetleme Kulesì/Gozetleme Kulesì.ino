#include <Servo.h>
Servo motor;
#define trigPin 6
#define echoPin 5
#define buzzer  9

int flag = 1;
int derece = 0;
void setup() {
  motor.attach(3);
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode (buzzer, OUTPUT);
}
void loop() {
   motor.write(derece);
  long sure, mesafe;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;
   if (mesafe > 50 || mesafe < 0){
    Serial.println("Menzil Disi");
    digitalWrite(buzzer,LOW);
   }
   else {
    Serial.print(mesafe);
    Serial.print(" cm");
    Serial.println("  Hedef Yakın ");
    digitalWrite(buzzer,HIGH);
    delay(3000);
   }
  if(flag == 1){
    derece +=5;  
    if(derece == 180){
      flag = 0;
    }
  }

  if(flag == 0){
    derece -=5;
    if(derece == 0){
      flag = 1;
    }
  } 
  delay(500);
}
