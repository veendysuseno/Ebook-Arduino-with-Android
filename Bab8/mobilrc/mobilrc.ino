// -----------------------------------------
// Sketsa untuk menggerakkan mobil
//   dengan handphone sebagai remote control 
// -----------------------------------------

#include <SoftwareSerial.h>

const int PIN_2 = 2;
const int PIN_3 = 3;
const int PIN_4 = 4;
const int PIN_5 = 5;

SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  bt.begin(9600);

  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_5, OUTPUT);

  digitalWrite(PIN_2, LOW);
  digitalWrite(PIN_3, LOW);
  digitalWrite(PIN_4, LOW);
  digitalWrite(PIN_5, LOW);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
    perintah = bt.readString();  

  if (perintah.length() != 0) {
    if (perintah == "MAJU") {
      digitalWrite(PIN_2, HIGH);
      digitalWrite(PIN_3, LOW);
      
      digitalWrite(PIN_4, HIGH);
      digitalWrite(PIN_5, LOW);  
    }
    else if (perintah == "MUNDUR") {
      digitalWrite(PIN_2, LOW);
      digitalWrite(PIN_3, HIGH);
      
      digitalWrite(PIN_4, LOW);
      digitalWrite(PIN_5, HIGH);
    }
    else if (perintah == "KIRI") {
      digitalWrite(PIN_2, HIGH);
      digitalWrite(PIN_3, LOW);
      
      digitalWrite(PIN_4, LOW);
      digitalWrite(PIN_5, LOW);
    }
    else if (perintah == "KANAN") {
      digitalWrite(PIN_2, LOW);
      digitalWrite(PIN_3, LOW);
      
      digitalWrite(PIN_4, HIGH);
      digitalWrite(PIN_5, LOW);
    }
    else if (perintah == "STOP") {
      digitalWrite(PIN_2, LOW);
      digitalWrite(PIN_3, LOW);
      
      digitalWrite(PIN_4, LOW);
      digitalWrite(PIN_5, LOW);
    }
  }
}

