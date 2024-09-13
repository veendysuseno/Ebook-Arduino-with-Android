// ------------------------------------------------------
// Contoh sket untuk menangani perintah AT untuk HC-06
//   menggunakan Serial Monitor
// ------------------------------------------------------

#include <SoftwareSerial.h>

const int RX = 9;
const int TX = 10; 
SoftwareSerial bt(RX, TX); 
 
void setup() {
  Serial.begin(9600);
 
  // Kecepatan HC-06 
  bt.begin(9600);
  
  Serial.println("Ketik perintah AT:");
}
 
void loop() {
  // Baca dan kirim perintah
  String perintah;
  
  if (Serial.available()) {
    Serial.print("\nPerintah: ");
    
    perintah = Serial.readString();    
      
    Serial.println(perintah);  
    bt.print(perintah);
  }
  
  // Baca dari HC-06 dan kirim ke Serial Monitor
  if (bt.available()) {
    while (bt.available()) 
      Serial.write(bt.read()); 
  }  
}

