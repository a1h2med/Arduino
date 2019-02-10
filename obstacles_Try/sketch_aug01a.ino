int motor1[] = {7, 8}, motor2[] = {6, 9}, motor3[] = {3, 5}, echo = 2, trig = 4;
float distance = 0, duration = 0;
void rotateright()
{
  digitalWrite(motor2[0], HIGH);
  digitalWrite(motor2[1], LOW);
  digitalWrite(motor3[0], LOW);
  digitalWrite(motor3[1], HIGH);
}
void rotateleft ()
{
  digitalWrite(motor2[0], LOW);
  digitalWrite(motor2[1], HIGH);
  digitalWrite(motor3[0], HIGH);
  digitalWrite(motor3[1], LOW);
}
float ultrasonic()
{
  int echo = 2, trig = 4;
  float take = 0, give = 0;
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  take = pulseIn(echo, HIGH);
  give = (take * .034) / 2;
}
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 2; i++)
  {
    pinMode(motor1[i], OUTPUT);
    pinMode(motor2[i], OUTPUT);
    pinMode(motor3[i], OUTPUT);
  }
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic();
  if (distance <= 200)
  {
    for (int i = 0; i < 2; i++)
    {
      digitalWrite(motor2[i], LOW);
      digitalWrite(motor3[i], LOW);
    }
  }
  delay(100);
  if (distance <= 200)
  {
    digitalWrite(motor1[0], HIGH);
    digitalWrite(motor1[1], LOW);
    distance = ultrasonic();
    if (distance>200)
    {
      rotateleft();       // m4 mot2kd mn l lfa
    }
    delay(500);
    digitalWrite(motor1[0], LOW);
    digitalWrite(motor1[1], HIGH);
    distance=ultrasonic();
    if (distance>200)
    {
      rotateright();
    }
    delay(500);
  }
}
