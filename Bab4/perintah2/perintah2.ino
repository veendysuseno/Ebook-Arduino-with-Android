// ----------------------------------
// Contoh untuk memperoleh string
//   dengam menggunakan readString() 
// ----------------------------------

void setup() {
  Serial.begin(9600);
}

void loop() {   
  String perintah;
  
  if (Serial.available() != 0)
    perintah = Serial.readString();
     
  if (perintah.length() != 0) {
    Serial.print("Perintah: ");
    Serial.println(perintah);
  }
}
    

