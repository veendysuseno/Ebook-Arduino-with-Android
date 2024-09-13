// ------------------------------------------------
// Contoh untuk menguji Ethernet Shield
//   untuk menjalankan skrip lihattabel.php
// ------------------------------------------------

#include <SPI.h>
#include <Ethernet.h>

// Alamat server -> Perlu diganti dengan domain Anda
char server[] = "ardualpha.net16.net";

// Alamat MAC 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Deklarasi objek klien
EthernetClient klien;

void setup() {
  Serial.begin(9600);
  
  // Koneksi ke Ethernet
  Ethernet.begin(mac);
  
  // Waktu untuk Ethernet shield menyelesaikan inisialisasi
  delay(1000);
  
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
