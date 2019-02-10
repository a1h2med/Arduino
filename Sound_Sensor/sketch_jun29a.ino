byte SoundSensor= 8;float value=0;
void setup() {
  // put your setup code here, to run once:
pinMode(SoundSensor,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
value = analogRead (A0);
Serial.println(value);
}
