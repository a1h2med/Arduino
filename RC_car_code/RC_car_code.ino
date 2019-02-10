int echo1=13,trig1=12;
int echo2=7,trig2=8;
int motor1[]={10,11},motor2[]={9,6},motor3[]={2,4},servo[]={5,3};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(echo1,OUTPUT);
pinMode(echo2,OUTPUT);
pinMode(trig1,INPUT);
pinMode(trig2,INPUT);
for (int i=0;i<2;i++)
{
  pinMode(motor1[i],OUTPUT);
  pinMode(motor2[i],OUTPUT);
  pinMode(motor3[i],OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig1,HIGH);
digitalWrite(trig2,HIGH);
delayMicroseconds(1000);
digitalWrite(trig1,LOW);
digitalWrite(trig2,LOW);
int take=pulseIn(echo1,HIGH);
int donno=pulseIn(echo2,HIGH);
int distance=take/2;
int space=donno/2;















}
