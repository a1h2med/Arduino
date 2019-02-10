int BR = 5, FR = 6, BL = 9, FL = 10; //front left motor, back left motor, front right motor, back right motor
int rs = 13, cs = 12, ls = 8; //right sensor, centre sensor, left sensor
int lastTurn = 0;
void setup() 
{
  pinMode(BR, OUTPUT);
  pinMode(FR, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(FL, OUTPUT);
  pinMode(rs, INPUT);
  pinMode(cs, INPUT);
  pinMode(ls, INPUT);
  analogWrite(FL,50);
  analogWrite(FR,50);
  Serial.begin (9600);
}

void loop() {
  int left = digitalRead(ls);
  int cen = digitalRead(cs);
  int right = digitalRead(rs);
  Serial.println (left);
 
  if (left == 1 && cen == 1 && right == 1)
  {
    if (lastTurn == 0)
    {
      goto h;
    }
    else if (lastTurn == 1)
    {
      goto l;
    }
    else if (lastTurn == 2)
    {
      goto v;
    }
  }
  else if ((left == 1 && cen == 0 && right == 1) || (left==0 && cen==0 && right==0)||(left==1 && cen==1 && right==1)) //all on white or all on black move forward
  {
h:  lastTurn = 0;
    analogWrite(FL,50);
    analogWrite(FR, 50);
    digitalWrite(BL, LOW);
    digitalWrite(BR, LOW);
  }
  else if ((left == 1 && cen == 1 && right == 0) || (left == 1 && cen == 0 && right == 0)) //right turn
  {
l: lastTurn = 1 ;
    analogWrite(BR, 50);
    analogWrite(FL, 50);
    digitalWrite(FR, LOW);
    digitalWrite(BL, LOW);
  }
  else if ((left == 0 && cen == 1 && right == 1) || (left == 0 && cen == 0 && right == 1)) //turn left
  {
v: lastTurn  = 2;
    analogWrite(BR, 50);
    analogWrite(FL, 50);
    digitalWrite(FR, LOW);
    digitalWrite(BL, LOW);
  }
}



