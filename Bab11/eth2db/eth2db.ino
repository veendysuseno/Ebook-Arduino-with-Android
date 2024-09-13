//------------------------------------------
// Contoh pengiriman data ke database server
// menggunakan Ethernet Shield 
//------------------------------------------

#include <dht.h>
#include <Ethernet.h>
#include <SPI.h>

const int PIN_DHT = A0;

// Alamat server -> Perlu diganti dengan domain Anda
char server[] = "ardualpha.net16.net";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetClient klien;

dht DHT;

float t = 0;  // Suhu
float h = 0;  // Kelembaban
String data;

void setup() { 
  Serial.begin(9600);

  // Koneksi ke Ethernet
  Ethernet.begin(mac);

  DHT.read11(PIN_DHT);
  h = DHT.humidity;
  t = DHT.temperature;

  data = "suhu=" + String(t) + "&kelembaban=" + String(h);

  Serial.println("Koneksi ke server...");
  
  if (klien.connect(server, 80)) { 
    Serial.println("Terhubung ke server");
    
    klien.println("POST /simpan_data.php HTTP/1.1"); 
    klien.print("Host: ");
    klien.println(server); 
    klien.println("Content-Type: application/x-www-form-urlencoded"); 
    klien.print("Content-Length: "); 
    klien.println(data.length()); 
    klien.println(); 
    klien.print(data); 

    Serial.println(data);
    
    klien.stop();
  } 
}

void loop() {
  
}




