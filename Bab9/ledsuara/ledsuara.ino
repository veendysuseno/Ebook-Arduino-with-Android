// ----------------------------------
// Contoh pengontrolan LED
//   dengan suara 
// ----------------------------------

#include <SoftwareSerial.h>

const int PIN_LED = 12;

SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
     perintah = bt.readString();
  
  if (perintah.length() != 0) {
    Serial.println(perintah); 
    perintah.toUpperCase();
    if (perintah == "LAMPU HIDUP") 
      digitalWrite(PIN_LED, HIGH);
    else if (perintah == "LAMPU MATI") 
      digitalWrite(PIN_LED, LOW);
  }
}
    

