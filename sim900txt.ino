#include <SoftwareSerial.h>

SoftwareSerial myserial(7, 8);

String textMessage;
const int relay1 = 10;
const int relay2 = 11;
const int relay3 = 12;
const int relay4 = 13;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  
  Serial.begin(19200); 
  myserial.begin(19200);
  delay(2000);
  Serial.print("readyTOgo...");
  myserial.print("AT+CMGF=1\r"); 
  delay(100);
  myserial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop(){
  if(myserial.available()>0){
    textMessage = myserial.readString();
    Serial.print(textMessage);    
    delay(10);
  } 
 if(textMessage.indexOf("ON1")>=0){
    digitalWrite(relay1, LOW);
    textMessage = ""; 
  }
  if(textMessage.indexOf("OF1")>=0){
    digitalWrite(relay1, HIGH);
    textMessage = "";
  }
  if(textMessage.indexOf("ON2")>=0){
    digitalWrite(relay2, LOW); 
    textMessage = "";
  }
  if(textMessage.indexOf("OF2")>=0){
    digitalWrite(relay2, HIGH);
    textMessage = "";
  }
  if(textMessage.indexOf("ON3")>=0){
    digitalWrite(relay3, LOW); 
    textMessage = "";
  }
  if(textMessage.indexOf("OF3")>=0){
    digitalWrite(relay3, HIGH);
    textMessage = "";
  }
  if(textMessage.indexOf("ON4")>=0){
    digitalWrite(relay4, LOW); 
    textMessage = "";
  }
  if(textMessage.indexOf("OF4")>=0){
    digitalWrite(relay4, HIGH);
    textMessage = "";
  }
    if(textMessage.indexOf("AL1")>=0){
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW); 
    textMessage = "";
  }
  if(textMessage.indexOf("AL0")>=0){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    textMessage = "";
  }
}
