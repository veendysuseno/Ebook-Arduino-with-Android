// ------------------------------------------------------
// Contoh untuk menyimpan data dengan Arduino WiFi Shield
//   ke database server per 30 detik
// ------------------------------------------------------

#include <dht.h>
#include <SPI.h>
#include <WiFi.h>

const int PIN_DHT = A0;

// Alamat server -> Perlu diganti dengan domain Anda
char server[] = "ardualpha.net16.net";

char ssid[] = "aka";         // SSID
char pass[] = "2345678901";  // Password

// Deklarasi objek klien
WiFiClient klien;

int status = WL_IDLE_STATUS;

dht DHT;

float t = 0;  // Suhu
float h = 0;  // Kelembaban
String data;

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
