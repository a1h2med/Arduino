#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11,10); //RX, TX


void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
digitalWrite(9,HIGH);
Serial.begin(9600);
BTSerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }
}
