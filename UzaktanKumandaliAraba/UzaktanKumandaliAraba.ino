#include <SoftwareSerial.h>

SoftwareSerial bluetoothModulu(2,3); 
/* Arduino  ->  Bluetooth modulu
  2 (Rx)   ->  Tx
  3 (Tx)   ->  Rx
*/

const int r_1 = 10;//sag arti
const int r_2 = 11;//sag eksi
const int l_1 = 12;//sol arti
const int l_2 = 13;//sol eksi
#define trigPin 6
#define echoPin 5

char drctn; 

void setup() {
  pinMode(r_1,OUTPUT);
  pinMode(r_2,OUTPUT);
  pinMode(l_1,OUTPUT);
  pinMode(l_2,OUTPUT);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  bluetoothModulu.begin(9600);
  
}
void forward(){
  digitalWrite(r_1,HIGH);
  digitalWrite(r_2,LOW);
  digitalWrite(l_1,HIGH);
  digitalWrite(l_2,LOW);
}
void reverse(){
  digitalWrite(r_1,LOW);
  digitalWrite(r_2,HIGH);
  digitalWrite(l_1,LOW);
  digitalWrite(l_2,HIGH);
}

void turn_left(){
  digitalWrite(r_1,LOW);
  digitalWrite(r_2,HIGH);
  digitalWrite(l_1,HIGH);
  digitalWrite(l_2,LOW);
}

void turn_right(){
  digitalWrite(r_1,HIGH);
  digitalWrite(r_2,LOW);
  digitalWrite(l_1,LOW);
  digitalWrite(l_2,HIGH);
}
void duramk(){
  digitalWrite(r_1,LOW);
  digitalWrite(r_2,LOW);
  digitalWrite(l_1,LOW);
  digitalWrite(l_2,LOW);
}

char okunanKarakter;
void loop() {
  long sure,mesafe;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;

  while(bluetoothModulu.available()>0){ /* Yeni veri var mı */
    okunanKarakter = bluetoothModulu.read(); /* Yeni veriyi okunanKarakter degiskenine kaydet */
    switch(okunanKarakter){ /* Okunan karaktere göre işlem yap */
      
      case'w' : //ileri git
        forward();
        delay(150); 
        break;
    
      case's' : //geri git
        reverse();
        delay(150);
        break;      
      case'd' : //saga dön
        turn_right();
        delay(150); 
        break;
      case'a' : //sola dön
        turn_left();
        delay(150); 
        break;
      case'f':
        duramk();
        break;  
    }
  }
}
