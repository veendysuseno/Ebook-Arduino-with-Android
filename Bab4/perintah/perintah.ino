// ----------------------------------
// Contoh untuk memperoleh string
//   yang berasal dari Serial Monitor 
// ----------------------------------

void setup() {
  Serial.begin(9600);
}

void loop() {   
  String perintah;
  
  while (Serial.available() != 0) {
     char data = Serial.read();
     perintah = perintah + data;
     
     delay(20); // Tunda sebentar untuk menyiapkan
                //  pembacaan data berikutnya
  }  

  if (perintah.length() != 0) {
    Serial.print("Perintah: ");
    Serial.println(perintah);
  }
}
    

