#include <stdlib.h>
byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1;
float take =0 ,give = 0 ;long value[4];
char state,current ;
char distance[4];
void forward ()  
{                
    digitalWrite(motor1,LOW);
    analogWrite(motor2,100);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
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
  int val;
      val=analogRead(0);   //connect mic sensor to Analog 0
      if (val <= 561 && val >=516 )
      val = 0;
      if (val =! 0)
      x++;
      return x;
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(RS,INPUT) ;
pinMode(LS,INPUT) ;
pinMode(MS,INPUT) ;
}

void loop() {
  // put your main code here, to run repeatedly:
      while (Serial.available())
  {
    float timer = 0;int number = 0,result=0;
    current = Serial.read();
    for (int i=0;i<4;i++)      // hena h5zn l distance 
    {
    distance[i] = Serial.read();
    value[i] = atol(distance);
    number++;
    if (distance[i]=='\0')
    break;
    }
    for (int i=0;i<number;i++)    // hena b7awl a5ly l array kloh fe variable wa7d
    {
      if (i==0)
      result+=value[i];
      else{
        result = result * 10;
        result+=value[i];
      }
    }
    if (result == 10)
    {
      forward();
      int y = reading();
      if (y == 1)
      Stop();
    }
      
      Serial.println(val,DEC);//print the sound value to serial        
      delay(100);
}
}
