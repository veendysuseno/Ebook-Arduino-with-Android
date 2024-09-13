// ----------------------------------
// Contoh untuk mengontrol LED
//   via Bluetooth menggunakan
//   perintah LED ON dan LED OFF
// ----------------------------------

#include <SoftwareSerial.h>

const int PIN_LED = 12;

SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  pinMode(PIN_LED, OUTPUT);
  
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
    perintah = bt.readString();  

  if (perintah.length() != 0) {
    if (perintah == "LED ON") {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED dihidupkan..");
    }
    else if (perintah == "LED OFF") {
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED dimatikan...");      
    }
  }
}

