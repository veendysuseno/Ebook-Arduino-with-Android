// ---------------------------------------
// Contoh untuk mengontrol dua motor servo
//   dengan Android
// ---------------------------------------

#include <SoftwareSerial.h>
#include <Servo.h>

const int PIN_SERVO_A  = 4;
const int PIN_SERVO_B  = 5;

// Buat objek
SoftwareSerial bt(9, 10); // RX, TX

Servo motorServoA, motorServoB;

void setup() {
  Serial.begin(9600); // Untuk kepentingan debugging
  
  // Motor servo dihubungkan ke pin servo
  motorServoA.attach(PIN_SERVO_A);
  motorServoB.attach(PIN_SERVO_B); 

  // Atur posisi awal servo motor
  motorServoA.write(0);
  motorServoB.write(0);

  // Atur kecepatan transfer data di bluetooth
  bt.begin(9600);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
    perintah = bt.readString();
  
  if (perintah.length() != 0) {
    // Cek perintah
    if (perintah.substring(0, 2) == "A=" ||
        perintah.substring(0, 2) == "B=") {
      Serial.println(perintah);
          
      // Buang newline terakhir
      perintah.trim();
     
      // Cari posisi newline terakhir
      int awal;
      int posisi = perintah.lastIndexOf("\n");
      if (posisi == -1) // Tidak ditemui
         awal = 0;
      else
         awal = posisi + 1;
         
      // Ambil perintah terakhir
      perintah = perintah.substring(awal);
          
      // Peroleh string sudut
      String strSudut = perintah.substring(2);
      
      // Peroleh sudut untuk motor servo
      int sudut = strSudut.toInt();
      Serial.print("-------------\nSudut= ");
      Serial.println(sudut);
      
      // Gerakkan motor servo
      if (perintah.substring(0,2) == "A=") {
         motorServoA.write(sudut);
         Serial.println("Servo A diputar");
      }
      else
         if (perintah.substring(0,2) == "B=") {
           motorServoB.write(sudut);
           Serial.println("Servo B diputar");
         }
    }
  }
}
    

