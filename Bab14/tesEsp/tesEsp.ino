// ----------------------------------
// Contoh pengujian esp8266 ESP-01
//   untuk menguji koneksi ke Wi-Fi
// ----------------------------------
  
#include <SoftwareSerial.h>

const int LAJU_BIT = 9600;
const String SSID = "aka";
const String PASS = "2345678901";
   
SoftwareSerial esp8266(8, 9); // RX, TX Arduino

void setup() {
  // Inisialisasi port serial
  Serial.begin(LAJU_BIT);

  // Inisialisasi esp8266
  esp8266.begin(LAJU_BIT);

  // Buang data dari esp8266 kalau ada   
  while(esp8266.available())
    esp8266.read();
      
  // Untuk menguji modul sudah siap atau belum
  esp8266.println("AT+RST");
  esp8266.flush();
  delay(1000);
  Serial.println("Modul di-reset...");
  if (esp8266.available()) {
    if (esp8266.find("OK")) 
       Serial.println("Modul sudah siap!");
    else {
      Serial.println("Modul tidak siap!");
      while(1);
    }
  }
  else {
    Serial.println("Modul tidak siap!");
    while(1);
  }
        
  delay(1000);
     
  // Tes koneksi ke Wi-Fi
  boolean terhubung = false;
  for (int i = 0; i < 5; i++) {
    if (koneksiKeWiFi()) {
      terhubung = true;
      break;
    }
  }
}

void loop() {

}
     
boolean koneksiKeWiFi() {
  esp8266.println("AT+CWMODE=1");
  String perintah="AT+CWJAP=\"" + SSID + "\",\"" +
                  PASS + "\"";
       
  esp8266.println(perintah);
  Serial.println(perintah);
  delay(2000);
       
  if (esp8266.find("OK")) {
    Serial.println("WiFi terhubung!");
    return true;
  }
  else {
    Serial.println("Koneksi ke WiFi gagal!");
    return false;
  }
}
       
