// -------------------------------
// Contoh pengendalian motor servo
// -------------------------------

#include <Servo.h>

const int PIN_SERVO  = 4;

// Buat objek
Servo motorServo;

void setup() {
  // Motor servo dihubungkan ke pin servo
  motorServo.attach(PIN_SERVO);  
}

void loop() {  
  motorServo.write(0);
  delay(2000);
  
  //motorServo.write(90);
  delay(2000);
  
  //motorServo.write(135);
  delay(2000);
}

