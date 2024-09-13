// ---------------------------
// Contoh println() 
//   untuk bilangan real
// ---------------------------

void setup() 
{
  Serial.begin(9600);

  float bil = 123.3157;

  Serial.println(bil);
  Serial.println(bil, 0);
  Serial.println(bil, 1);
  Serial.println(bil, 2);
  Serial.println(bil, 3);
}

void loop() 
{

}

