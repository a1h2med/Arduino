#include<SoftwareSerial.h>
char data;
SoftwareSerial myserial(10,11);
void setup()
{  //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
    myserial.begin(9600); 
    Serial.begin(9600);
}
void loop()
{
   if(myserial.available() )      // Send data only when you receive data:
   {
      data = myserial.read();        //Read the incoming data & store into data
   Serial.print(data);
   }
      if(data == '1') 
      {// Checks whether value of data is equal to 1
         digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
         //delay(100);
      }
      else if(data == '0')     
      {//  Checks whether value of data is equal to 0
         digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
       //  delay(100);
      }
}
