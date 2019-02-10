byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4;
float take =0 ,give = 0 ;
char state; 
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

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  take = pulseIn(echo, HIGH);
  give = (take * .034) / 2;
  if(give<=20)
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW); 
    delay(1000);
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
    delay(200);
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
    delay(500);
    x=1;
  }
  else
  {
    if(x==1)
    {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
   }
while(Serial.available())
{
  state = Serial.read();
  Serial.println(state);
  if (state == 'F')
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
  }
  if (state == 'B')  // move back
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
  }
  if (state == 'L') // move left
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
  }
  if (state == 'R') // move right
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
 }
  if (state == 'W')
  goto  AA;
}
}
AA :
 if((digitalRead(LS) && digitalRead(RS) ) || digitalRead(MS))     //FOrward
  {     
    analogWrite(motor1,127);
    digitalWrite(motor2,LOW);
    analogWrite(motor3,127);
    digitalWrite(motor4,LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS) &&  !(digitalRead(MS)) )     //right
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    analogWrite(motor3,127);
    digitalWrite(motor4,LOW);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)) && !(digitalRead(MS)) )     //left
  {
    analogWrite(motor1,127);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)) && !(digitalRead(MS)) )     //stop
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW); 
  }
} 
