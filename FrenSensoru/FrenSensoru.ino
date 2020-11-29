// Deneme 1 
// Fren Sensörü

int pushButon = 2;
int butondurum;

void setup() {
 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  pinMode(pushButon, INPUT);
   Serial.begin(9600);
}

void loop() {

  for(int i = 3 ; i < 8 ; i++ )
  { 
  delay(50);
  digitalWrite(i, HIGH);
  }
  
  for( int j = 6 ; j > 3 ; j-- ) 
  {
  delay(50);
  digitalWrite(j, LOW);
     
 }
  delay(75);

  butondurum = digitalRead(pushButon);
  Serial.println (butondurum);
  delay(1);
  
  
    

}
