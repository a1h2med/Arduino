int motorpin1 = 3;
int motorpin2 = 4;
int enable = 5;
int state;
void setup() {
  // put your setup code here, to run once:
pinMode(motorpin1,OUTPUT);
pinMode(motorpin2,OUTPUT);
pinMode(enable,OUTPUT);
digitalWrite(enable,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)
state=Serial.read();
if (state=='0')
{
  digitalWrite(motorpin1,LOW);
  digitalWrite(motorpin2,LOW);
}
else if (state=='1')
{
  digitalWrite(motorpin1,HIGH);
  digitalWrite(motorpin2,LOW);
}
else if (state=='2')
{
  digitalWrite(motorpin1,LOW);
  digitalWrite(motorpin2,HIGH);
}
}
