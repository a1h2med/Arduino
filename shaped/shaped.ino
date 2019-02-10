byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1 , SoundSensor = 8;
float take =0 ,give = 0 ;int counter = 0 , RightSmooth =0, Right = 0 , LeftSmooth = 0 , Left = 0;
int cc = 0;
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
    digitalWrite(motor4,LOW);
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
void circle()
{
  analogWrite(motor1,0);
  analogWrite(motor2,150);
  analogWrite(motor3,0);
  analogWrite(motor4,50);
  //this values change to get the redious required which is equal to 1 m 
  }
void loop() {
  // put your main code here, to run repeatedly:
        // infinity //
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
  delay (25000);
  cc = 0;
  while (1) 
  {
    forward();
      int y = 0;
      y = reading();
      if (y == 30)
      {
        turnLeft ();
        delay(450 );
        cc++;
        x = 0;
        if (cc == 3)
        break;
      }
  }
  delay (25000);
  while (1)
  {
  circle();
  
  }
  delay (25000);
}
