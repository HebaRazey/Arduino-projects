Const int enablePin = 6;  //(PWM pin)
Const int input1 = 5;     
Const int input2 = 4;      

Void setup() 
{
  pinMode(enablePin, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

Void loop()
 {
  //Tests Forward Direction
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  testSpeeds();  //run speed test for forward dir

  delay(3*1000);  //delay before changing direction

  //Tests Reverse Direction
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  testSpeeds();  //Run speed test for reverse dir

  delay(3*1000);  //delay before next loop
}

Void testSpeeds()
 {
  //list of PWM values from ~0% to 100% speed
  Int dutyCycles[] = {0, 128, 190, 255}; //0%, 50%, 75%, 100%

  For (int i = 0; i<4 ; i++) {
    analogWrite(enablePin, dutyCycles[i]);
    delay(3*1000);  //run at this speed for 2 seconds
  }

  //stop motor
  analogWrite(enablePin, 0);
}
