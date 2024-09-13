// -----------------------------------
// Contoh komunikasi dua arah
//   dengan Bluetooth
// -----------------------------------

#include <dht.h>
#include <SoftwareSerial.h>

const int PIN_DHT = A0;

dht DHT;
SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  bt.begin(9600);
}

void loop() {   
  String perintah;
  
  if (bt.available() != 0) 
    perintah = bt.readString();  

  if (perintah.length() != 0) {
    DHT.read11(PIN_DHT);
    if (perintah == "SUHU") {
      bt.print("Suhu = ");
      bt.println(DHT.temperature);  
    }
    else if (perintah == "KELEMBABAN") {
      bt.print("Kelembaban = ");
      bt.println(DHT.humidity);      
    }
  }
}

