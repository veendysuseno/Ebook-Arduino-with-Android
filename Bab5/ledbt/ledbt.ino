// --------------------------------------------
// Contoh pengendalian LED
//   via Bluetooth dan Bluetooth Terminal 
// --------------------------------------------                                                                                                                                     --------------------------------------------

#include <SoftwareSerial.h>

const int PIN_LED = 12;

SoftwareSerial bt(9, 10); // RX, TX

void setup() {
  // Atur kecepatan transfer data di bluetooth
  bt.begin(9600);
  
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  char dataBt; // Data dari bluetooth
  
  if (bt.available( ) > 0) {
    dataBt = bt.read();
    if (dataBt == 13)
      Serial.println();
    else  
      Serial.print(dataBt);

    // Proses 0 dan 1
    if (dataBt == '1')
      digitalWrite(PIN_LED, HIGH);
    else if (dataBt == '0')
      digitalWrite(PIN_LED, LOW);
        
  }
}

