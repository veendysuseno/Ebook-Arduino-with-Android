// -----------------------------------
// Contoh untuk mengontrol kunci pintu
// -----------------------------------

#include <SoftwareSerial.h>
#include <Servo.h>

const int PIN_SERVO  = 4;

SoftwareSerial bt(9, 10); // RX, TX
Servo motorServo;

void setup() {
  Serial.begin(9600);

  bt.begin(9600);

  // Motor servo dihubungkan ke pin servo
  motorServo.attach(PIN_SERVO);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
    perintah = bt.readString();  

  if (perintah.length() != 0) {

    if (perintah == "Buka Pintu") {
      motorServo.write(90);
      Serial.println("Pintu dibuka...");
    }
    else if (perintah == "Tutup Pintu") {
      motorServo.write(0);
      Serial.println("Pintu ditutup...");      
    }
  }
}

