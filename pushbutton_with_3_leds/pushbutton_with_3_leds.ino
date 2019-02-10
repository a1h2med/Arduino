#define r 3
#define y 4
#define g 5
#define pb 6
int x ;

void setup() {
pinMode(r,OUTPUT);
pinMode(y,OUTPUT);
pinMode(g,OUTPUT);
pinMode(pb,INPUT);
x=1 ;}
void loop() {
 int m = digitalRead (pb);
if (m == HIGH){
  while(x ==1){
    digitalWrite(r,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
    if(m == LOW) {break;}
    }
  while(x ==2){
    digitalWrite(y,HIGH);
    digitalWrite(r,LOW);
    digitalWrite(g,LOW);
    if(m == LOW) {break;}
    }
  while(x ==3){
    digitalWrite(g,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(r,LOW);
    if(m == LOW) {break;}
   } if(x==4){
  x=0;}
    x++;
}
else{
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
  }
  
}
