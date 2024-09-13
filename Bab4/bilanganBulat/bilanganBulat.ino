// ---------------------------
// Contoh println() 
//   untuk bilangan bulat
// ---------------------------

void setup() 
{
  Serial.begin(9600);

  int bil = 70;

  Serial.println(bil);
  Serial.println(bil, DEC);
  Serial.println(bil, HEX);
  Serial.println(bil, OCT);
  Serial.println(bil, BIN);
}

void loop() 
{

}

