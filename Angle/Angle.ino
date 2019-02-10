byte   d = 0;
byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1 , SoundSensor = 8;
float take =0 ,give = 0 ;int counter = 0 , RightSmooth =0, Right = 0 , LeftSmooth = 0 , Left = 0;
char state;int current, i=0 ,dd =0 , gg = 0, number = 0 , p = 0 ;
char distance[4];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(echo,INPUT);
pinMode(RS,INPUT) ;
pinMode(LS,INPUT) ;
pinMode(MS,INPUT) ;
pinMode(trig,OUTPUT);
}
void Stop ()
{
  digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,0);
}
void turnRight ()
{
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,200);
}
void loop() {
  // put your main code here, to run repeatedly:
    i = 0;dd=0;
while (Serial.available() )
  {
    dd=1;
    current = Serial.read();
    distance[i] = current - 48;
    i++;
    if (current == 47 || current == 58 )
    {
      break;
    }
  }
  if (dd == 1)
  {
    if (i == 3)
    {
    number = distance[0]*100+distance[1]*10+distance[2];
    Serial.println(number);
    p = number/10;
    if (number > 90 && number < 170)
    {turnRight(); p = p -9;
      delay(500+p*50);Stop();
    }
    if (number == 170)
    { turnRight();delay(875);Stop();}
    if (number == 180)
    { turnRight();delay(900);Stop();}
    if (number > 180 && number < 240)
    {turnRight();p = p - 18 ;delay(900+p*50);Stop();}
    if (number > 230 && number < 280)
    {turnRight(); p = p - 23 ;delay(1150+p*25);Stop();}
    if (number == 280)
    {turnRight();delay(1300);Stop();}
    if (number > 280 && number <= 360)
    {turnRight(); p = p - 28 ;delay(1300+p*25);Stop();}
    }
    else if (i == 2)
    {
    number = distance[0]*10+distance[1];
    Serial.println(number);
    p = number/10;
    if (number == 10)
    {turnRight();
    delay(100);Stop();}
    if (number > 10 && number < 80 || number == 90)
    {turnRight();delay(100+p*50);Stop();}
    if (number == 80)
    {turnRight();delay(100+7*50+25);Stop();}
    } }
    else int u = 0;
    }
