 int motor2pin1=6;
 int motor2pin2=7;
int motorPin1 = 3; // pin 2 on L293D IC
int motorPin2 = 4; // pin 7 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int state;

void setup() {
    // sets the pins as outputs:
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motor2pin1,OUTPUT);
    pinMode(motor2pin2,OUTPUT);
    pinMode(enablePin, OUTPUT);
    // sets enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
    }   
    // if the state is '0' the DC motor will turn off
    if (state == '0') {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
    }
    // if the state is '1' the motor will turn right
    else if (state == '1') {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
    }
    // if the state is '2' the motor will turn left
    else if (state == '2') { 
        digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
    }
    else if (state=='5')
    {
      digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        digitalWrite(motor2pin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motor2pin2, LOW); // set pin 7 on L293D low
    }
    else if (state=='6')
    {digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
    digitalWrite(motor2pin1, LOW); // set pin 2 on L293D high
        digitalWrite(motor2pin2, HIGH); // set pin 7 on L293D low
    }
}
 
