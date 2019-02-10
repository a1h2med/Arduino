byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1 , SoundSensor = 8;
float give = 0 ,mind = 0;int counter = 0 , RightSmooth =0, Right = 0 , LeftSmooth = 0 , Left = 0;int what = 0,take =0 ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(echo,INPUT);
pinMode(RS,INPUT) ;
pinMode(LS,INPUT) ;
pinMode(MS,INPUT) ;
pinMode(SoundSensor,INPUT);
pinMode(trig,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
take = millis();
what = take*10^(-6);
give = cos(take);
mind = sin(2*take)/2;
    analogWrite(motor1,0);
    analogWrite(motor2,give*255);
    analogWrite(motor3,0);
    analogWrite(motor4,mind*255);
    Serial.println(give);
}
