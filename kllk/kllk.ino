void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(9,LOW);
}
