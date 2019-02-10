#include <PID_v1.h>
//Define Variables we'll be connecting to
double Setpoint, Input, Output;
//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);
void setup()
{
 //initialize the variables we're linked to
 Setpoint = 10;
 //turn the PID on
 myPID.SetMode(AUTOMATIC);
 Serial.begin(9600);
}
void loop()
{
 Input = analogRead(A0);
myPID.Compute();
 analogWrite(3,Output);
 Serial.println(Output);
}
