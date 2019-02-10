byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1;
float take =0 ,give = 0 ;
char state;  
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
pinMode(trig,OUTPUT);
}
void forward()
{
  digitalWrite(motor1,LOW);
    analogWrite(motor2,100);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
}
void loop() {
  // put your main code here, to run repeatedly:
  left = digitalRead(LS);
  right = digitalRead(RS);
  med = digitalRead(MS);
  Serial.print ("left " );
  Serial.println (left);
//  Serial.print ("right" );
//  Serial.println (right );
//  Serial.print ("center" );
//  Serial.println (med );
 if( (left && right && !med) == 1)     //FOrward
  forward();
  
  if ( (left && med && !right  ) == 1 )   //right
  {
    digitalWrite(motor1,LOW);
    analogWrite(motor2,0);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,150);
  }
  
  if( (right && med  && !left )  == 1 )     //left
  {
    while (1)
    {
    digitalWrite(motor1,LOW);
    analogWrite(motor2,150);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,0);
    if ( digitalRead(MS) == 0)
    {
    forward();
    break;}
    if ( digitalRead (LS) == 0)
    {
      digitalWrite(motor1,LOW);
    analogWrite(motor2,150);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
    break;
    }
    }
  }
  if ( ( right && !left && !med ) == 1 )
  {
    digitalWrite(motor1,LOW);
    analogWrite(motor2,150);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
  }
  if ( ( left && !right && !med ) == 1 )
  {
    digitalWrite(motor1,LOW);
    analogWrite(motor2,100);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,150);
  }
  if( (right && left && med) == 1 )     //stop
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW); 
  }
}
