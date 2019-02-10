byte enA = 10, enB = 11, tempPin = A1; // dh pins bta3t l h-bridge 34an at7k fe l motors we lazm ykono analog
byte led = 13, led2 = 12, ldr = A0; int echo = 7, trig = 8; float distance = 0;
byte motor1[2] = {3, 5}, motor2[2] = {6, 9}, motor3[2] = {2, 4}; // dh pins l motors
char state;         // dh char b5zn feh ly hyb3toh
//.     // l pins ly m4 most5dma heya (        7           ,           8          )
void turnRight()
{
  digitalWrite(motor1[0], LOW);
  digitalWrite(motor1[1], HIGH);
  digitalWrite(motor2[0], HIGH);
  digitalWrite(motor2[1], LOW);
}
void turnLeft()
{
  digitalWrite(motor2[0], LOW);
  digitalWrite(motor2[1], HIGH);
  digitalWrite(motor1[0], HIGH);
  digitalWrite(motor1[1], LOW);
}
void moveForward()                    // dh function 34an ym4y forward
{
  digitalWrite(motor1[0], HIGH);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor2[0], HIGH);
  digitalWrite(motor2[1], LOW);
}
void moveBack()                      // dh function 34an ym4y back we tb3n dh ht3ks function l forward
{
  digitalWrite(motor1[0], LOW);
  digitalWrite(motor1[1], HIGH);
  digitalWrite(motor2[0], LOW);
  digitalWrite(motor2[1], HIGH);
}
void Stop()                        // dh function 34an y3ml stop lma y4el his hand mn l zorar 34an mykml4 m3 nfsoh we ntl3 ngry wrah ^_^ we yarb ttl4 s7
{
  digitalWrite(motor1[0], LOW);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor2[0], LOW);
  digitalWrite(motor2[1], LOW);
}
void moveFRight()                // dh function 34an ym4y forward we y5o4 ymen
{
  digitalWrite(motor2[0], HIGH);
  digitalWrite(motor2[1], LOW);
  for (int i = 255; i >= 63; i -= 5)    // feeeeeeeeeeeeeeeeeeeeeeeeeeeeeeh 88888888lllllllllllllllllllllltttttttttt hena
  {
    analogWrite(enA, i);        // dh pin bta3t l t7akom 34an at7km fe l motor a2ll wa7d we az0d l tany 34an y2dr ylf
  }
  digitalWrite(motor1[0], LOW);
  digitalWrite(motor1[1], LOW);
}
void moveFLeft()               // dh function 34an ym4y forward we y5o4 4mal
{
  digitalWrite(motor1[0], HIGH);
  digitalWrite(motor1[1], LOW);
  for (int i = 255; i >= 63; i -= 5)
  {
    analogWrite(enB, i);     // l pin bta3t l control 34an a3rf at7km fe l motor a7awel a2ll l speed bta3t wa7d we azod l tany
  }
  digitalWrite(motor2[0], LOW);
  digitalWrite(motor2[1], LOW);
}
void turn1 ()
{
  turnRight();
  delay(500);
  Stop();
}
void turn2()
{
  turnLeft();
  delay(500);
  Stop();
}
float temp()
{
  int reading = analogRead(tempPin);
  float voltage = reading * 3.3;
  voltage /= 1024;
  float Temprature_in_C = (voltage - .33) * 100;
  delay(1000);
}
float ultrasonic()
{
  int echo = 7, trig = 8;
  float take = 0, give = 0;
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  take = pulseIn(echo, HIGH);
  give = (take * .034) / 2;
}
void stop_the_motor ()
{
  digitalWrite(motor3[0], LOW);
  digitalWrite(motor3[1], LOW);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);        // lazm a3ml l serial dh 34an azbot l speed bta3t enoh yb3t we yst2bl
  for (int i = 0; i < 2; i++)  // dh loop 3amelha 34an ylf 3la kol l pins bta3t l motors we y5leha output m4 4rt tt3ml kdh Na 3amlha ksl m4 aktr ^_^
  {
    pinMode(motor1[i], OUTPUT);
    pinMode(motor2[i], OUTPUT);
    pinMode(motor3[i], OUTPUT);
  }
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic();
  if (distance <= 100)
  {
    Stop();
    digitalWrite(motor3[0], HIGH);
    digitalWrite(motor3[1], LOW);
    delay(500);
    stop_the_motor();
    float what = ultrasonic();
    if (what > 100)
    {
      turn1();
    }
    else
    {
      digitalWrite(motor3[1], HIGH);
      digitalWrite(motor3[0], LOW);
      delay(500);
      stop_the_motor();
      float damage = ultrasonic();
      if (damage > 100)
        turn2();
      else
      {
        turnRight();
        delay(1000);
        Stop();
      }
    }
  }
  else {
    float see = temp();
    if (see == 30)
    {
      Stop();
    }
    else
    {
      while (Serial.available())        // 3aml while 34an tol m hwa byb3t afdl a5od we available dh enoh by4of hwa mwgod wla l2
      {
        state = Serial.read();          // dh bb7ot ly 2tb3t fe l variable state we abd2 a5o4 fe loops b2a y4ofoh hy3ml anhy function mn ly fo2
        Serial.print(state);
        if (state == 'F')
          moveForward();
        else if (state == 'I')
          moveFRight();
        else if (state == 'G')
          moveFLeft();
        else if (state == 'R')    // dh function 34an ylf 7walen nfsoh bs llymen
          //turn right
          turnRight();
        else if (state == 'L')  // dh function 3amlha 34an ylf 7walen nfsoh bs 4mal
          // turn left
          turnLeft();
        else if (state == 'B')
          // turn back
          moveBack();
        else if (state == 'R')
          // stop
          Stop();
        else if (state == 'T')
        {
          float Temprature = temp();
          Serial.print(Temprature);
        }
      }
    }
  }
  int statues = analogRead(ldr);
  if (statues <= 800)
  {
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    turnRight();
  }
  else
  { digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
  }
}
