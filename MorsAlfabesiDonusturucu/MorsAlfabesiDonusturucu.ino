void kelime(){
  delay(250);
  digitalWrite(9,HIGH);
  delay(250);
  digitalWrite(9,LOW);
}
void harf(){
  delay(250);
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);
}
void point(){
  delay(250);
  digitalWrite(7,HIGH);
  delay(150);
  digitalWrite(7,LOW); 
}
void line(){
  delay(250);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
}
String str = "";
char ch;

int Lenght_str(String str){
  int count = 0;
  while(str[count] != '\0'){
    count++;
  }
  return count;
}
void setup(){

  pinMode(7,OUTPUT);
  Serial.begin(9600);
}
void loop(){

   if(Serial.available() > 0){
        str = Serial.readStringUntil('\n');
    }
 Serial.println(str);
 
 for(int i=0; i< Lenght_str(str) ; ++i){
    delay(10);
  
    switch(str[i]){
      case 'a':
          point();
          line();
              break;
      case 'b':
          line();
          point();
          point();
          point();
              break;
      case 'c':
          line();
          point();
          line();
          point();
              break;
      case 'd':
          line();
          point();
          point();
              break;
      case 'e':
            point();
            
              break;
      case 'f':
            point();
            point();
            line();
            point();
              break;
      case 'g':
            line();
            line();
            point();
              break;
      case 'h':
            point();
            point();
            point();
            point();
              break;
      case 'i':
            point();
            point();
              break;
      case 'j':
            point();
            line();
            line();
            line();
              break;
      case 'k':
            line();
            point();
            line();
            
              break;
      case 'l':
            point();
            line();
            point();
            point();
              break;
      case 'm':
            line();
            line();
            
              break;
      case 'n':
            line();
            point();
              break;
      case 'o':
          line();
          line();
          line();
              break;
      case 'p':
            point();
            line();
            line();
            point();
              break;
      case 'q':
            line();
            line();
            point();
            line();
              break;
      case 'r':
            point();
            line();
            point();
              break;
      case 's':
            point();
            point();
            point();
              break;
      case 't':
            line();
              break;
      case 'u':
            point();
            point();
            line();
              break;
      case 'w':
            point();
            line();
            line();
              break;
      case 'x':
            line();
            point();
            point();
            line();
              break;
      case 'v':
            point();
            point();
            point();
            line();
              break;
      case 'y':
            line();
            point();
            line();
            line();
              break;
      case 'z':
            line();
            line();
            point();
            point();
              break;
      case ' ':
            kelime();
            break;        
    }
    if(str[i] != ' ')
       harf();
  } 
  str = "";
}

 
