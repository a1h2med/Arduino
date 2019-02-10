byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0;
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
  left = digitalRead(LS);
  right = digitalRead(RS);
  med = digitalRead(MS);
  Serial.print ("left " );
  Serial.println (left);
//  Serial.print ("right" );
//  Serial.println (right );
//  Serial.print ("center" );
//  Serial.println (med );
 if( (left && right && !digitalRead(MS)) == 1)     //FOrward
  {     
    analogWrite(motor1,LOW);
    digitalWrite(motor2,255);
    analogWrite(motor3,LOW);
    digitalWrite(motor4,255);
  }
  
  if( ((left && med)  ) == 1 )    //right
  {
    digitalWrite(motor1,255);
    digitalWrite(motor2,LOW);
    analogWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
  }
  
  if( (right && med)  == 1 )     //left
  {
    analogWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,255);
    digitalWrite(motor4,LOW);
  }
  
  if( (right && left && med) == 1 )     //stop
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW); 
  }
}
