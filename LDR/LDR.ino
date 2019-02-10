int led=13,led2=12,ldr=A0;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(ldr,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int statues=analogRead(ldr);
if (statues<=800)
{
digitalWrite(led,HIGH);
digitalWrite(led2,HIGH);
}
else 
{
digitalWrite(led,LOW);
digitalWrite(led2,LOW);
}
}
