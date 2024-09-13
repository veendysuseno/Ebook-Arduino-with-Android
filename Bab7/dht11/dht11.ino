// -----------------------------------
// Contoh penggunaan sensor DHT11
//     untuk mengukur kelembaban udara
//     dan suhu udara
// -----------------------------------

#include <dht.h>

const int PIN_DHT = A0;

dht DHT;

void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian kelembaban dan suhu udara");
}

void loop() {
  DHT.read11(PIN_DHT);
  Serial.print("Kelembaban udara = ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  Serial.print("Suhu = "); 
  Serial.println(DHT.temperature);
  
  delay(1000); // Diperlukan oleh DHT11 
}

