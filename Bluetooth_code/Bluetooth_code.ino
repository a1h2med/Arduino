#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial MySerial(10, 11); //RX, TX
//int pos=0;
//int take=8;
//int give=7;
//Servo myservo;
char val; // variable to receive data from the serial port
// int led = 13; 
void setup() {
  MySerial.begin(9600);  // start serial communication at 9600bps
  //myservo.attach(9);
 // pinMode(take,OUTPUT);
 // pinMode(give,OUTPUT);
}
void loop() {
  if( MySerial.available() )       // if data is available to read
  {
    val = MySerial.read();         // read it and store it in 'val'
  }
  if( val == 'H' )               // if 'H' was received
  {
    for (int pos=0;pos<=180;pos++)
    {
    myservo.write(pos);
    delay(15);
    }
  }
  else if (val== 'w')
  {
    take
  }
  else if (val== 'y')
  {
  } 
  else {
    for (int pos=180;pos>=0;pos++)
    {
      myservo.write(pos);
      delay(15);
    } 
    }
  }
  delay(100);                    // wait 100ms for next reading
}
