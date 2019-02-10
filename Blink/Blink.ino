int pin6=6;//B2-motor forward right 
int pin9=9;//B1-motor reversr right 
int pin3=3;//A2-motor forward left
int pin5=5;//A1-motor reverse left
char BluetoothData;
void setup() {
pinMode(pin6,OUTPUT);
pinMode(pin9,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin5,OUTPUT);
Serial.begin(9600);
}
void loop() {
while (Serial.available()){
BluetoothData=Serial.read();
if(BluetoothData=='F')//FORWARD MOTION 
{
digitalWrite(pin6,HIGH);
digitalWrite(pin9,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin5,LOW);
}
if(BluetoothData=='B')//BACK MOTION 
{
digitalWrite(pin6,LOW);
digitalWrite(pin9,HIGH);
digitalWrite(pin3,LOW);
digitalWrite(pin5,HIGH);
}
if(BluetoothData=='L')//LEFT MOTION 
{ 
digitalWrite(pin6,LOW);
digitalWrite(pin9,HIGH);
digitalWrite(pin3,HIGH);
digitalWrite(pin5,LOW);
}
if (BluetoothData=='R')//RIGHT MOTION 
{
digitalWrite(pin6,HIGH);
digitalWrite(pin9,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin5,HIGH);
}
if(BluetoothData=='S')
{
digitalWrite(pin6,LOW);
digitalWrite(pin9,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin5,LOW);
}
}
}
