//original code by [Diyar Hussein-Traffic lights]
//modified by me

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(4, HIGH); // For green LED
  delay(3000); // Wait for 3 second
  digitalWrite(4, LOW);

  
  digitalWrite(3, HIGH); // For orange LED
  delay(1000);  // Wait for 1 second
  digitalWrite(3, LOW);
  
  
  digitalWrite(2, HIGH);  // For the red LED
  delay(3000); // Wait for 3 second
  digitalWrite(2, LOW); 
}
