
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9,HIGH);
delayMicroseconds(1000);
digitalWrite(9,LOW);
int duration=pulseIn(10,HIGH);
int distance=duration/2;
Serial.println(distance);
if (distance>=200 && distance<=500)
{
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
else if (distance<200)
{
   digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
}
delay(1000);
}
