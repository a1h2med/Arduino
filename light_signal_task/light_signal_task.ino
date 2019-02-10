#define r 3 
#define y 4 
#define g 5 


void setup() {
pinMode(r,OUTPUT);
pinMode(y,OUTPUT);
pinMode(g,OUTPUT);
}

void loop() {
digitalWrite(r,HIGH);
delay(6000);
digitalWrite(r,LOW);
digitalWrite(y,HIGH);
delay(3000);
digitalWrite(y,LOW);
digitalWrite(g,HIGH);
delay(6000);
digitalWrite(g,LOW);
digitalWrite(y,HIGH);
delay(3000);
digitalWrite(y,LOW);
}
