// -------------------------------------------------
// Contoh untuk menguji WiFi Shield CC3000
//   untuk merekam data ke database server
// -------------------------------------------------

#include <dht.h>
#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <string.h>

const int PIN_DHT = A0;

#define ADAFRUIT_CC3000_IRQ   3  // Pin interupsi
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10

Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, 
                                         ADAFRUIT_CC3000_IRQ, 
                                         ADAFRUIT_CC3000_VBAT,
                                         SPI_CLOCK_DIVIDER); 

#define WLAN_SSID     "aka"         // Tukar dengan SSID Anda
#define WLAN_PASS     "2345678901"  // Tukar dengan password SSID
#define WLAN_SECURITY WLAN_SEC_WPA2 // Sesuikan dengan jenis sekuritas

const char server[] = "ardualpha.net16.net";
unsigned long ip;

Adafruit_CC3000_Client klien; 

dht DHT;

float t = 0;  // Suhu
float h = 0;  // Kelembaban
String data;

void setup(void) {
  Serial.begin(9600);

  init_CC3000();   // Inisialisasi CC3000      

  DHT.read11(PIN_DHT);
  h = DHT.humidity;
  t = DHT.temperature;

  data = "suhu=" + String(t) + "&kelembaban=" + String(h);

  Serial.println("Koneksi ke server...");

  // Mencoba koneksi ke server maksimum 100 kali
  int maks = 100;
  int pencacah = 0;

  while (!klien.connected() && pencacah < maks) {
    klien.connect(server, 80);
    if (klien.connected())
      break;
      
    pencacah++;
    delay(10);
  }

  // Permintaan ke server
  if (klien.connected()) { 
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
  }
}

void loop(void) {
  // Untuk memeriksa kiriman dari server 
  if (klien.available()) {
    char karakter = klien.read();
    Serial.print(karakter);
  }
}

void init_CC3000() {
  Serial.println("Inisialisasi CC3000 ...");
  
  if (!cc3000.begin())
  {
    Serial.println("Gagal melakukan initialisasi  CC3000!");
    while(1);
  }
  
  // Koneksi ke hot spot
  Serial.print("Koneksi ke SSID: "); 
  Serial.println(WLAN_SSID);
  
  if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    Serial.println("Gagal!");
    while(1);
  }
   
  Serial.println("Terhubung!");
}
