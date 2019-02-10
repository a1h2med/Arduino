#include<Servo.h>
#include<SoftwareSerial.h>
SoftwareSerial myserial(11,12);
Servo myservo;
char check;
char main=' ';
int first_motor[]={4,5};
void moveForward()
{
  digitalWrite(first_motor[0],HIGH);
  digitalWrite(first_motor[1],LOW);
}
void moveBack()
{
  digitalWrite(first_motor[0],LOW);
  digitalWrite(first_motor[1],HIGH);
}
void turnRight()
{
  digitalWrite(first_motor[0],HIGH);
  digitalWrite(first_motor[1],LOW);
  for (int i=0;i<=180;i++)
  {
    myservo.write(i);
    delay(10);
  }
}
void turnLeft ()
{
  digitalWrite(first_motor[0],HIGH);
  digitalWrite(first_motor[1],LOW);
  for (int i=180;i<=0;i++)
  {
    myservo.write(i);
    delay(10);
  }
}

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
myserial.begin(9600);
for (int i=0;i<2;i++)
{
  pinMode(first_motor[i],OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
if(myserial.available()>0)
{
  check=myserial.read();
  main=myserial.read();
}
if (check=='w')
{
  if (main==' ')
  // forward only
  moveForward();
  else if(main=='R')
  // forward and tries to get right
{
  moveForward();
  turnRight();
}
  else if(main=='L')
  // forward and tries to get left
  {
    moveForward();
    turnLeft();
  }
}
else if (check=='R')
// turn right
turnRight();
else if (check=='L')
//turn left
turnLeft();
else if (check=='B')
// back
moveBack();
/*else if (check=='S')
// stop */
}
