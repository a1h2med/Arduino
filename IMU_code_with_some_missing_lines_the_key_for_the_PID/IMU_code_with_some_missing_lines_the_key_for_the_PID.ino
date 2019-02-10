#include <Wire.h>
float theTime = 0 , timePrev = 0 , elapsedTime = 0;
void setup() {
  // put your setup code here, to run once:
Wire.begin(); //begin the wire comunication
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(250000);
  theTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  timePrev = theTime;
  theTime = millis ();
   elapsedTime = (theTime - timePrev) / 1000; 
  // for the accelerometer
     Wire.beginTransmission(0x68);
     Wire.write(0x3B); //Ask for the Address register- correspond to AcX
     Wire.endTransmission(false);
     Wire.requestFrom(0x68,6,true); 
     Acc_rawX=Wire.read()<<8|Wire.read();


     Acceleration_angle[0] = atan((Acc_rawY/16384.0)/sqrt(pow((Acc_rawX/16384.0),2) + pow((Acc_rawZ/16384.0),2)))*rad_to_deg;
     /*---Y---*/
     Acceleration_angle[1] = atan(-1*(Acc_rawX/16384.0)/sqrt(pow((Acc_rawY/16384.0),2) + pow((Acc_rawZ/16384.0),2)))*rad_to_deg;

     
     // for the Gyroscope 
     
   Wire.beginTransmission(0x68);
   Wire.write(0x43); //Gyro data first adress 
   Wire.endTransmission(false);
   Wire.requestFrom(0x68,4,true); //Just 4 registers
   Gyr_rawX=Wire.read()<<8|Wire.read();




   Gyro_angle[0] = Gyr_rawX/131.0; 
   /*---Y---*/
   Gyro_angle[1] = Gyr_rawY/131.0;

   /*---X axis angle---*/
   Total_angle[0] = 0.98 *(Total_angle[0] + Gyro_angle[0]*elapsedTime) + 0.02*Acceleration_angle[0];
   /*---Y axis angle---*/
   Total_angle[1] = 0.98 *(Total_angle[1] + Gyro_angle[1]*elapsedTime) + 0.02*Acceleration_angle[1];
             //////////// please Note ////////
             
             
             ////  I wrote most of the code of the IMU there's still some parameteres missing *_^

             ////  please note that The input of the PID will be the Total_angle [1] as it's in the Y direction 
             ////  عشان لما الروبوت يميل لقدام او لورا هيرمي معاك بتغيير ف ال y حاول تتخيل الروبوت ده عباره عن ورقه 2D ولما يحصل تغيير ههيبان ف ال y
            
              //// F E E L     F R E E     T O        A S K    A N Y     Q U E S T I O N    Y O U    H A V E   ^_^
     
}
