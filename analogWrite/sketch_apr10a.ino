float val=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(A0);
analogWrite(3,val/4);
Serial.println(val);
}
