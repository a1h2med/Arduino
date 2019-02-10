#include<PID_v1.h>
byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4,left=0 , right = 0 , mid = 0 ,Kp=25 , Kd = 2.05, Ki= 1 ,Max = 90;
float take =0 ,give = 0 ;
double output = 0 ,lineInput=0 , setPoint = 0;
char state; 

PID myPid (&lineInput, &output ,&setPoint , Kp, Ki, Kd, DIRECT);
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
myPid.SetMode(AUTOMATIC);
}

void loop() {
  // put your main code here, to run repeatedly:
  left = digitalRead(LS);
  right = digitalRead(RS);
  mid = digitalRead(MS);
  Serial.println(left);
  if ( mid == 0 && right == 1 && left == 1 )
  {
    analogWrite(motor2,150);
    digitalWrite(motor1,LOW);
    analogWrite(motor4,150);
    digitalWrite(motor3,LOW);
  }
  if ( left == 0 && mid == 0 && right == 1)
  {
    analogWrite(motor2,150);
    digitalWrite(motor1,LOW);
    analogWrite(motor4,90);
    digitalWrite(motor3,LOW);
  }
  if ( right == 0 && mid == 0 && left == 1)
  {
    digitalWrite(motor2,90);
    digitalWrite(motor1,LOW);
    analogWrite(motor4,150);
    digitalWrite(motor3,LOW);
  }
  if ( right == 0 &&  mid == 1 && left == 1 )
  {
    analogWrite ( motor2 , 200 );
    digitalWrite (motor1 , LOW);
    digitalWrite ( motor4 , LOW );
    digitalWrite (motor3 , LOW );
  }
  
 if( mid == 1 && right == 1 && left == 0 )     
  {     
    digitalWrite ( motor1 , LOW );
    digitalWrite (motor2 , LOW );
    analogWrite ( motor3 , 200 );
    digitalWrite (motor4 , LOW );
  }
  
//  if((left && !right &&  mid) == 1)     //right
//  {
//    digitalWrite(motor1,LOW);
//    digitalWrite(motor2,LOW);
//    analogWrite(motor3,output);
//    digitalWrite(motor4,LOW);
//  }
//  
//  if( (!left && right && mid) || ( !left && !mid )  == 1 )     //left
//  {
//    analogWrite(motor1,output);
//    digitalWrite(motor2,LOW);
//    digitalWrite(motor3,LOW);
//    digitalWrite(motor4,LOW);
//  }
//  
//  if( ( left && right && mid ) == 0 )     //stop
//  {
//    digitalWrite(motor1,LOW);
//    digitalWrite(motor2,LOW);
//    digitalWrite(motor3,LOW);
//    digitalWrite(motor4,LOW); 
//  }
}
