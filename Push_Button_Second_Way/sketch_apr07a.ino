void setup() {
  // put your setup code here, to run once:
pinMode (8,OUTPUT);
pinMode (7, INPUT);
}

int state = 0;
int times = 0;

void loop() {
state = digitalRead(7);
if(state == 1){
  times = times + 1;
}
if(times%2 == 0){
  digitalWrite(8,LOW);
}else{
  digitalWrite(8,HIGH);
}
}
