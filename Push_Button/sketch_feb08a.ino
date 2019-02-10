int val ;
void setup()
{
   pinMode(13,OUTPUT);
   pinMode(7,INPUT);
}
void loop()
{
   val=digitalRead(7);
   digitalWrite(13,val);
}

