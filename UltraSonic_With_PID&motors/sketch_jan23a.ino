int position1=20;
int Kp=100;
int Kd=20;
int Ki=30;
int echo=5;
int trig=6;
int motor1=3;
int motor2=5;
void setup() {
  // put your setup code here, to run once:
pinMode (motor1,OUTPUT);
pinMode (motor2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor2,LOW);
  position2=analogRead (echo);
  float x= millis();
while (1)
{
  float position3=analogRead (echo);
  float error = position1 - position2;
   float differ = error * Kp;
   analogWrite(motor1,differ);
   if (error==0)
   break;
}
while (1)
{
  float position3=analogRead (echo);
  float y=millis();
  float rate = y-x;
  float error =position1 - position3;
  float done = Kd * (error / rate );
  analogWrite (motor1,done);
  float x= millis();
  if (error==0)
  break;
}
while (1)
{
  float error1=position1 - position2;
  float position3=analogRead (echo);
  float y=millis();
  float rate = y-x;
  float error2=postion3 - position1;
  float baby=Ki * (error1+error2 * rate);
  analogWrite (motor1,baby);
  position2=analogRead (echo);
  float x= millis();
  if (error2==0)
  break;
}
}
