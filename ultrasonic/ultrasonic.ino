int motor1[] = {7, 8}, motor2[] = {6, 9}, motor3[] = {3, 5}, echo = 2, trig = 4;
float distance = 0, duration = 0;
float ultrasonic()
{
  int echo = 2, trig = 4;
  float take = 0, give = 0;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  take = pulseIn(echo, HIGH);
  give = (take * .034) / 2;
}
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
delay(500);
Serial.println(distance);
digitalWrite(3,LOW);
digitalWrite(5,HIGH);
delay(500);
Serial.println(distance);
}
