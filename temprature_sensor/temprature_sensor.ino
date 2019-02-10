int tempPin=A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
     int reading=analogRead(tempPin);
     float voltage=reading*5;
     voltage/=1024;
     float Temprature_in_C=(voltage-.5)*100*-1;
     Serial.println(Temprature_in_C);
     delay(1000);
}
