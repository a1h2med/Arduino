float x = 0;
void setup() {
  // put your setup code here, to run once:
pinMode (13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x = analogRead(A0);
x = x * .48828125;
Serial.println(x);
if (x > 40)
  digitalWrite(13,HIGH);
else if (x < 40)
  digitalWrite(13,LOW);
delay (1000);
} 
