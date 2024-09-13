const int PIN_R = 13;
const int PIN_G = 12;
const int PIN_B = 11;

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

  // Matikan semua LED
  digitalWrite(PIN_R, LOW);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_B, LOW);
}

void loop() {
  // Merah menyala
  digitalWrite(PIN_R, HIGH);
  delay(2000);
  digitalWrite(PIN_R, LOW);

  // Hijau menyala
  digitalWrite(PIN_G, HIGH);
  delay(2000);
  digitalWrite(PIN_G, LOW);

  // Biru menyala
  digitalWrite(PIN_B, HIGH);
  delay(2000);
  digitalWrite(PIN_B, LOW);

  // Hijau dan biru menyala
  digitalWrite(PIN_G, HIGH);
  digitalWrite(PIN_B, HIGH);
  delay(2000);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_B, LOW);
}

