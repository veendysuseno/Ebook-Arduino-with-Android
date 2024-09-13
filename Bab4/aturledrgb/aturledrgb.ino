// ----------------------------------
// Contoh untuk mengontrol LED RGB
//   berjenis common anode
//   melalui Serial Monitor 
// ----------------------------------

const int PIN_R = 13;
const int PIN_G = 12;
const int PIN_B = 11;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  
  digitalWrite(PIN_R, HIGH);
  digitalWrite(PIN_G, HIGH);
  digitalWrite(PIN_B, HIGH);
}

void loop() {   
  String perintah;
  
  if (Serial.available() != 0) 
     perintah = Serial.readString();
  
  if (perintah.length() != 0) {
    // Konversi ke string dengan huruf kapital
    perintah.toUpperCase();
    
    if (perintah == "LEDR ON") {
      digitalWrite(PIN_R, LOW);
      Serial.println("LED Merah dihidupkan..");
    }
    else if (perintah == "LEDR OFF") {
      digitalWrite(PIN_R, HIGH);
      Serial.println("LED Merah dimatikan...");      
    }
    else if (perintah == "LEDG ON") {
      digitalWrite(PIN_G, LOW);
      Serial.println("LED Hijau dihidupkan..");
    }
    else if (perintah == "LEDG OFF") {
      digitalWrite(PIN_G, HIGH);
      Serial.println("LED Hijau dimatikan...");      
    }
    else if (perintah == "LEDB ON") {
      digitalWrite(PIN_B, LOW);
      Serial.println("LED Biru dihidupkan..");
    }
    else if (perintah == "LEDB OFF") {
      digitalWrite(PIN_B, HIGH);
      Serial.println("LED Biru dimatikan...");      
    }
  }
}
    

