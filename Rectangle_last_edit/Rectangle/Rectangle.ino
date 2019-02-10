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
void turnRight ()
{
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,200);
}
void circle()
{
  analogWrite(motor1,0);
  analogWrite(motor2,150);
  analogWrite(motor3,0);
  analogWrite(motor4,50);
  //this values change to get the redious required which is equal to 1 m 
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
      if (y == 30)
      {
        turnRight ();
        delay(450 );
        x = 0;
      }
  }
}
