// --------------------------------------------
// Contoh penguji komunikasi antara
//    Bluetooth di Arduino dan Handphone 
//    menggunakan SoftwareSerial
// --------------------------------------------                                                                                                                                     --------------------------------------------

#include <SoftwareSerial.h>

SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  // Atur kecepatan transfer data di bluetooth
  bt.begin(9600);
  
  Serial.begin(9600);
}

void loop() {
  char dataBt; // Data dari bluetooth
  
  if (bt.available( ) > 0) {
    dataBt = bt.read();
    if (dataBt == 13)
      Serial.println();
    else  
      Serial.print(dataBt);
  }
}

