// ----------------------------------
// Contoh untuk mengontrol LED
//   melalui Serial Monitor 
// ----------------------------------

const int PIN_LED = 12;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {   
  String perintah;
  
  if (Serial.available() != 0) 
     perintah = Serial.readString();
  
  if (perintah.length() != 0) {
    // Konversi ke string dengan huruf kapital
    perintah.toUpperCase();
    if (perintah == "LED ON") {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED dihidupkan..");
    }
    else if (perintah == "LED OFF") {
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED dimatikan...");      
    }
  }
}
    

