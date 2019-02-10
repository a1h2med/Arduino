byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1 , SoundSensor = 8;
float take =0 ,give = 0 ;int counter = 0 , RightSmooth =0, Right = 0 , LeftSmooth = 0 , Left = 0; String Signal; 
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
pinMode(SoundSensor,INPUT);
pinMode(trig,OUTPUT);
}
void forward ()  
{                
    digitalWrite(motor1,LOW);
    analogWrite(motor2,100);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
}
void turnLeft ()
{
    analogWrite(motor1,0);
    analogWrite(motor2,200);
    analogWrite(motor3,0);
    digitalWrite(motor4,0);
}
void turnRight ()
{
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,200);
}
void turnLeftSmooth ()
{
    analogWrite(motor1,150);
    analogWrite(motor2,0);
    analogWrite(motor3,75);
    analogWrite(motor4,0);
}
void turnRightSmooth ()
{
    analogWrite(motor1,0);
    analogWrite(motor2,150);
    analogWrite(motor3,0);
    analogWrite(motor4,75);
}
void Stop ()
{
    digitalWrite(motor1,LOW);
    analogWrite(motor2,0);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,0);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  Signal += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (Signal.length() > 0) {

  if(Signal == "*forward#")
  {
    forward();
    delay(100);
  }
//
//  else if(Signal == "*back#")
//  {
//  back();
//    delay(100);
//  }

  else if (Signal == "*left#")
  {
    turnLeft();
    delay(100);
  
  }

 else if ( Signal == "*right#")
 {
  turnRight();
    delay(100);
 }

 else if (Signal == "*stop#")
 {
   Stop ();
   delay (100);
 } } }
