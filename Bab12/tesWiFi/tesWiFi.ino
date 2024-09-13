// ------------------------------------------------
// Contoh untuk menguji Arduino WiFi Shield
//   untuk menjalankan skrip lihattabel.php
// ------------------------------------------------

#include <SPI.h>
#include <WiFi.h>

// Alamat server -> Perlu diganti dengan domain Anda
char server[] = "ardualpha.net16.net";

char ssid[] = "aka";         // SSID
char pass[] = "2345678901";  // Password

// Deklarasi objek klien
WiFiClient klien;

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);

  // Cek WiFi shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield tidak ada");
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
  
  Serial.println("Koneksi ke server...");

  if (klien.connect(server, 80)) {
    Serial.println("Terhubung---------");
    
    // Permintaan HTTP
    klien.println("GET /lihattabel.php HTTP/1.1");
    klien.print("Host: ");
    klien.println(server);
    klien.println("Connection: close");
    klien.println();
  } 
  else 
    Serial.println("Gagal-------------");
}

void loop() {
  // Untuk memeriksa kiriman dari server 
  if (klien.available()) {
    char karakter = klien.read();
    Serial.print(karakter);
  }
}
