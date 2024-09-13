// -----------------------------------
// Contoh untuk mengirimkan informasi
//     suhu dan kelembaban udara
//     melalui Bluetooth
// -----------------------------------

#include <dht.h>
#include <SoftwareSerial.h>

const int PIN_DHT = A0;

dht DHT;
SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  DHT.read11(PIN_DHT);
  
  bt.print("K=");
  bt.print(DHT.humidity);
  bt.print(",S=");
  bt.println(DHT.temperature);
 

  // untuk Serial Monitor 
  Serial.print("K=");
  Serial.print(DHT.humidity);
  Serial.print(",S=");
  Serial.println(DHT.temperature);
  
  delay(1000); // Diperlukan oleh DHT11 
}

