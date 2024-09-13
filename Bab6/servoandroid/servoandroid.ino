// -----------------------------------
// Contoh untuk mengontrol motor servo
//   dengan Android
// -----------------------------------

#include <SoftwareSerial.h>
#include <Servo.h>

const int PIN_SERVO  = 4;

// Buat objek
SoftwareSerial bt(9, 10); // RX, TX
Servo motorServo;

void setup() {
  // Motor servo dihubungkan ke pin servo
  motorServo.attach(PIN_SERVO); 

  // Atur kecepatan transfer data di bluetooth
  bt.begin(9600);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
    perintah = bt.readString();  

  if (perintah.length() != 0) {
    // Peroleh sudut untuk motor servo
    int sudut = perintah.toInt();
    motorServo.write(sudut);
  }
}
    

