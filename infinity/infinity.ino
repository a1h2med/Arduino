byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1 , SoundSensor = 8;
float take =0 ,give = 0 ;int counter = 0 , RightSmooth =0, Right = 0 , LeftSmooth = 0 , Left = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(echo,INPUT);
pinMode(RS,INPUT) ;
pinMode(LS,INPUT) ;
pinMode(MS,INPUT) ;
pinMode(SoundSensor,INPUT);
pinMode(trig,OUTPUT);
}
void forward ()  
{                
    digitalWrite(motor1,LOW);
    analogWrite(motor2,100);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
}
void turnLeft ()
{
    analogWrite(motor1,0);
    analogWrite(motor2,200);
    analogWrite(motor3,0);
    digitalWrite(motor4,0);
}
void turnRight ()
{
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,200);
}
void turnLeftSmooth ()
{
    analogWrite(motor1,150);
    analogWrite(motor2,0);
    analogWrite(motor3,75);
    analogWrite(motor4,0);
}
void turnRightSmooth ()
{
    analogWrite(motor1,0);
    analogWrite(motor2,150);
    analogWrite(motor3,0);
    analogWrite(motor4,75);
}
void Stop ()
{
    digitalWrite(motor1,LOW);
    analogWrite(motor2,0);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,0);
}
int reading ()
{
  int val = 0;
      val=analogRead(0);   //connect mic sensor to Analog 0
      if (val <= 466 && val >=422 )
      val = 0;
      if (val != 0)
      x++;
      delay(100);
      return x;
      if (x ==45)
      x = 0;
      Serial.println(x);
}
void loop() {
  // put your main code here, to run repeatedly:
  while (1) 
  {
    forward();
      int y = 0;
      y = reading();
      if (y == 45)
      {
        turnRight ();
        delay(600);
        x = 0;
        break;
      }
  }
  while (1) 
  {
    forward();
      int z = 0;
      z = reading();
      if (z == 25)
      {
        turnRight ();
        delay(600);
        x = 0;
        break;
      }
  }
  while (1) 
  {
    forward();
      int p = 0;
      p = reading();
      if (p == 45)
      {
        turnLeft ();
        delay(900);
        x = 0;
        break;
      }
  }
  while (1) 
  {
    forward();
      int m = 0;
      m = reading();
      if (m == 25)
      {
        turnLeft ();
        delay(850);
        x = 0;
        break;
      }
  }
//left = digitalRead(LS);
//  right = digitalRead(RS);
//  med = digitalRead(MS);
//  if ( (med == 0 ) && (left == 1) && (right == 1))
//  {
//  forward();
//  counter=millis();
//  }
//  
//  if ( (med == 0) && (left == 0) && (right == 1))
//  {
//  turnRightSmooth();
//  RightSmooth=millis();
//  }
//  if ( (med == 0 ) && (left == 1) && (right == 0))
//  {
//  turnLeftSmooth();
//  LeftSmooth=millis();
//  }
//  if ( (med == 1) && (right == 1) && (left == 0))
//  {
//    while (1)
//    {
//  turnLeft();
//  Left=millis();
//  if ( (digitalRead(MS) == 0) || (digitalRead(RS) == 0 ))
//  break;
//    }
//  }
//  if ( (med == 1) && (right == 0) && (left == 1))
//  {
//    while (1)
//    {
//  turnRight();
//  Right=millis();
//  if ( (digitalRead(MS) == 0) || (digitalRead(LS) == 0))
//  break;
//  }
//  }
//  if ( (med == 1) && ( right == 1) && (left == 1))
//  {
//    wait();
//   // Stop(); 
//  }
//  Serial.println(counter );Serial.println(RightSmooth);Serial.println(LeftSmooth);
}
