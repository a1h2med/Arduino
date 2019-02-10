#include "TimerOne.h" 
int timer_led = 13;
int interrupt_led = 12;
int button = 2;
int pot_pin = A6;
int pot_reading;
int Emotor = 6; //The enable pin in L293d
int dir1 = 7; //input 1
int dir2 = 8; //input 2
int motor_value; //The analog value to be written on the enable pin
void setup()
{

  pinMode(timer_led, OUTPUT);
  pinMode(interrupt_led, OUTPUT);
  pinMode(pot_pin, INPUT);
  pinMode(Emotor, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir1, OUTPUT);
  Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period  
  Timer1.attachInterrupt(Blink);  // attaches Blink() as a timer overflow interrupt
  
  attachInterrupt(0, toggle, RISING); //attach toggle() as an external interrupt function
  
  Serial.begin(9600); //initialize communication of serial monitor
}
 
void loop()
{
  // your program here...
  pot_reading = analogRead(pot_pin);
  Serial.print("Pot reading "); // printing the pot reading
  Serial.println(pot_reading);

  motor_value = map(pot_reading, 0, 1023, 0, 255); //rescalling of the pot reading
                                                   //to writting it on the enable pin 
  forward(motor_value); //passing the scaled value to the forward function
  delay(10); 
}

void toggle() //The external interrupt function
{
  digitalWrite(interrupt_led, !digitalRead(interrupt_led));
  
}
void Blink(){ //Timer overflow function
    digitalWrite(timer_led, !digitalRead(timer_led));
  }

void forward(int value){ //Spead control function
    analogWrite(Emotor, value);
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }

