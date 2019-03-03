// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
#include<Wire.h>
#include <PID_v1.h>
float Output=0;
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double originalSetpoint = -1256;
double setpoint = originalSetpoint;
double input, output;
int moveState=0; //0 = balance; 1 = back; 2 = forth
double Kp = 3.55;
double Kd = 2.08;
double Ki = 0.005;
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);
//MOTOR CONTROLLER
int ENA = 5;
int IN1 = 6;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int ENB = 12;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(ENA,OUTPUT);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  Serial.begin(9600);
  pid.SetMode(AUTOMATIC);
  pid.SetSampleTime(10);
  pid.SetOutputLimits(-255, 255);  
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(333);

  ////////////// .................... check ................./////////////////


  // see the equation of converting the degree into motor volatge



  // if it didn't work try the gyro readings


  /*
  if (AcX < setpoint ) {        // here you want to check whether to move forward or not 
    // depending on the value of the he ACX  
    //input = -AcX * 180/M_PI;
    input = AcX/1024;
    pid.Compute();
    Serial.println(output);
    analogWrite(IN1,-output);     
    analogWrite(IN2,0);
    analogWrite(IN3,-output);
    analogWrite(IN4,0);
     }
    */ 
    //input = AcX * 180/M_PI ;
    input = -AcX/1024;
    Output = input * 3.05;
    Serial.println(Output);
    if (Output < 0){
    analogWrite(IN1,0);           
    analogWrite(IN2,70);
    analogWrite(IN3,0);
    analogWrite(IN4,60);
     }
     else if (Output == 0 && AcX < -504 && AcX > -388){
    analogWrite(IN1,0);           
    analogWrite(IN2,0);
    analogWrite(IN3,0);
    analogWrite(IN4,0);
     }
     else {
    analogWrite(IN1,70);           
    analogWrite(IN2,0);
    analogWrite(IN3,60);
    analogWrite(IN4,0);
      }
  }
