// ------------------------------------------------------
// Contoh untuk menyimpan data dengan modul ESP-01
//   ke database server per 30 detik
// ------------------------------------------------------

#include <dht.h>
#include "WiFiEsp.h"
#include "SoftwareSerial.h"

const int PIN_DHT = A0;

SoftwareSerial esp8266(8, 9); // RX, TX

// Alamat server -> Perlu diganti dengan domain Anda
char server[] = "ardualpha.net16.net";

char ssid[] = "aka";         // SSID
char pass[] = "2345678901";  // Password

// Deklarasi objek klien
WiFiEspClient klien;

int status = WL_IDLE_STATUS;

dht DHT;

float t = 0;  // Suhu
float h = 0;  // Kelembaban
String data;

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);  // Inisialisasi untuk port ESP

  // Inisialisasi modul ESP 
  WiFi.init(&esp8266);
  // Cek WiFi shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("Modul WiFi tidak ada");
    // Stop
    while (true);
  }

  // Koneksi ke Wi-Fi
  while (status != WL_CONNECTED) {
    Serial.print("Koneksi ke SSID: ");
    Serial.println(ssid);
    // Koneksi ke WiFi
    status = WiFi.begin(ssid, pass);

    // Tunggu
    delay(10000);
  }

  IPAddress ip = WiFi.localIP();
  Serial.print("Alamat IP: ");
  Serial.println(ip);
}

void loop() {
  DHT.read11(PIN_DHT);
  h = DHT.humidity;
  t = DHT.temperature;

  data = "suhu=" + String(t) + "&kelembaban=" + String(h);

  Serial.println("Koneksi ke server...");

  if (klien.connect(server, 80)) {
    Serial.println("Terhubung---------");
    
    klien.println("POST /simpan_data.php HTTP/1.1"); 
    klien.print("Host: ");
    klien.println(server); 
    klien.println(
      "Content-Type: application/x-www-form-urlencoded"); 
    klien.print("Content-Length: "); 
    klien.println(data.length()); 
    klien.println(); 
    klien.print(data); 

    Serial.println(data);
    
    klien.stop();
  } 

  delay(30000); // Tunda per 30 detik
}
