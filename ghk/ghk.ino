/*#include<SoftwareSerial.h>
SoftwareSerial myserial(11,10);*/
byte motor1[2]={3,5},motor2[2]={6,9}; 
int check;
char state;
char main=' ';

void moveForward()
{
    digitalWrite(motor1[0],HIGH);
    digitalWrite(motor1[1],LOW);
    digitalWrite(motor2[0],HIGH);
    digitalWrite(motor2[1],LOW);
}
void moveBack()
{
  digitalWrite(motor1[0],LOW);
  digitalWrite(motor1[1],HIGH);
  digitalWrite(motor2[0],LOW);
  digitalWrite(motor2[1],HIGH);
}
void moveFRight()
{
  for (int i=0;i<=51;i++)
  {
    analogWrite(motor2[0],i*5);
    analogWrite(motor1[0],i);
  }
}
void moveFLeft()
{
   for (int i=0;i<=51;i++)
  {
    analogWrite(motor1[0],i*5);
    analogWrite(motor2[0],i);
  }
}
void setup() {
  // put your setup code here, to run once:
for (int i=0;i<2;i++)
{
  pinMode(motor1[i],OUTPUT);
  pinMode(motor2[i],OUTPUT);
}
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 digitalWrite(12,HIGH);
 digitalWrite(13,HIGH); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)
{
  check=Serial.read();
  state=Serial.read();
  main=Serial.read();
if (check=='1')
{
if (state=='F')
{
  if (main==' ')
  moveForward();
  else if (main=='R')
  //move forward and turn right
  {
    moveFRight();
  }
  else if (main=='L')
  //move forward and turn left
  {
    moveFLeft();
  }
}
else if (state=='R')
//turn right
{

  digitalWrite(motor1[0],LOW);
  digitalWrite(motor1[1],LOW);
  digitalWrite(motor2[0],HIGH);
  digitalWrite(motor2[1],LOW);
}
else if (state=='L')
// turn left
{
  digitalWrite(motor2[0],LOW);
  digitalWrite(motor2[1],LOW);
  digitalWrite(motor1[0],HIGH);
  digitalWrite(motor1[1],LOW);
}
else if (state=='B')
// turn back
moveBack();
}
}
} 
