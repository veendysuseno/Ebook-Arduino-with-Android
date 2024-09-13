// ----------------------------
// Contoh pemasukan teks
//   dari Serial Monitor 
// ----------------------------

void setup() {
  Serial.begin(9600);
}

void loop() {   
  while (Serial.available() != 0) {
     char data = Serial.read();
     Serial.print(data);
     
     delay(20); // Tunda sebentar untuk menyiapkan
                //  pembacaan data berikutnya
  }  
}

