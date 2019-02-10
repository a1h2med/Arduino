#include<SoftwareSerial.h>
char data;
char main=' ';
int second_motor[]={3,6};
SoftwareSerial myserial(10,11);
void setup() {
  // put your setup code here, to run once:
myserial.begin(9600);
Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (myserial.available())
{
  data=myserial.read();
 // main=myserial.read();
 Serial.print(data);
}
if (data=='1')
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
else if (data=='0')
{
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
}
