// -----------------------------------------
// Contoh pengujian perintah AT pada ESP8266
// -----------------------------------------

#include <SoftwareSerial.h>

const int LAJU_BIT = 9600;

SoftwareSerial esp8266(8, 9); // RX, TX

void setup() {
  Serial.begin(LAJU_BIT);
  esp8266.begin(LAJU_BIT);
  Serial.println("Berikan perintah AT...");
}

void loop() {
  // Baca hasil dari ESP8266
  while (esp8266.available()) {
    char kar = esp8266.read();
    if (kar < 32 && !(kar == '\n'))
      continue;
      
    Serial.print(kar);
  }

  // Kirim perintah ke ESP8266
  if (Serial.available()) {
    Serial.print("Perintah: ");
    while (Serial.available()) {
      char kar = Serial.read();
      Serial.write(kar);
      esp8266.write(kar);
    }  
  }
}
