byte x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1 , SoundSensor = 8;
int take =0 ,give = 0 ;
//pin for h-bridger motor controle
#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9


//pin sensor
#include<NewPing.h>
#define TRIGGER_PIN 11
#define ECHO_PIN    10
#define MAX_DISTANCE 50000

unsigned long previousMillis = 0;
const long interval = 1000;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//int for random turn direction
int ranturn = 0;
long r1 = 0;
long r2 = 500;

void setup() {
  pinMode( IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  unsigned long currentMillis = millis();//time for no delay
  unsigned long randomDirection=millis();//timer for setting random turn direction
  unsigned int uS = sonar.ping();        //check distance
if(randomDirection-r1 > r2&&ranturn==0){ //check to see if the corect time has passed
  ranturn= ranturn+1;                    // if time has passed and ranturn ==0 then set ranturn to 1
  r1=randomDirection;
}
else if(randomDirection-r1 > r2&&ranturn==1){
  ranturn = ranturn-1;//if ranturn is == to 1 set it to 0
  r1=randomDirection;
}
 //Serial.print(ranturn); 

  if (uS  >= 3000) //if every thing is clear go forward
  {
    forword(50);
  }
  else if (uS < 3000&&ranturn==0) // if something there turn left.
  {
    stay();
    delay(500);
    backword(90);
    delay(1000);
    left(100);
    delay(500);
    unsigned int uS2 = sonar.ping();
    if (uS2 < 2000){
      left(100);
      delay(500);
      unsigned int uS2 = sonar.ping();
        if (uS2 < 2000){
          left(100);
          delay(500);
      }
    }
     
  }
  else if (uS < 3000&&ranturn==1){
   stay();
   delay(500);
   backword(75);
   delay(500);
   right(100);
    delay(500);
    unsigned int uS2 = sonar.ping();
    if (uS2 < 2000){
      right(100);
      delay(500);
      unsigned int uS2 = sonar.ping();
        if (uS2 < 2000){
          right(100);
          delay(500);
      }
    }
  }
  Serial.print("uS");
  Serial.print(uS);
  Serial.println();
 // Serial.print("uS2");
  //Serial.print(uS2);
 //Serial.println();

    

}




void rm(int mode, int percent) //void setup for the right motor
{
  //change the percentage range of 0 -> 100 into the PWM
  //range of 0 -> 255 using the map function
int duty = map(percent, 0, 100, 0, 255);

  switch(mode)
  {
    case 0: //stop right motor
   digitalWrite(IN1, LOW);
    break;

    case 1: // right motor forword
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, duty);
    break;

    case 2: // right motor bacwords
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, duty);
    break;
    }

}
// end of void rm

void lm(int mode, int percent) //void setup for left motor
{
//change the percentage range of 0 -> 100 into the PWM
  //range of 0 -> 255 using the map function
  int duty = map(percent, 0, 100, 0, 255);
  
  switch(mode)
  {
    case 0: // stop left motor
    digitalWrite(ENB, LOW);  //set enable low to disable B
    break;

    case 1: // left motor forword
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, duty);
    break;

    case 2: // left motor backwords
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, duty);
    break;
  }
}
// end of void lm


void forword (int duty) //used to move robot forword. the duty sets the speed.
{
  rm(1,duty);
  lm(1,duty);
}

void backword (int duty)// used to move robot backwords
{
rm(2,duty);
lm(2,duty);
}
//
//void left (int duty) // turn robot left
//{
//  rm(1,duty);
//  lm(2,duty);
//}
//void right(int duty)//turn robot right
//{
//  rm(2,duty);
//  lm(1,duty);
//}
//
//void stay ()//stop robot
//{
//  rm(0,0);
//  lm(0,0);
//}

