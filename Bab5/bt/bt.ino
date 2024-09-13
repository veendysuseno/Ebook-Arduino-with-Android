// --------------------------------------------
// Contoh penguji komunikasi antara
//    Bluetooth di Arduino dan Handphone 
//    menggunakan objek Serial
//
//    Perhatian:
//    Jika mau memunggah sketsa ini, kabel yang
//    terhubung di pin 0 dan pin 1 harus
//    dicabut terlebih dahulu
// --------------------------------------------                                                                                                                                     --------------------------------------------

void setup() {
  // Atur kecepatan transfer data di bluetooth
  Serial.begin(9600);
}

void loop() {
  char dataBt; // Data dari bluetooth
  
  if (Serial.available() > 0) {
    dataBt = Serial.read();
    if (dataBt == 13)
      Serial.println();
    else  
      Serial.print(dataBt);
  }
}

