#include <Servo.h>

Servo myServo;
const int SERVO_POSITION_MAX = 180;
const int SERVO_POSITION_MIN = 0;
int myServoPosition = 0;

void setup() {

  Serial.begin(9600); //Start the serial port
  while(!Serial){;}
  
  myServo.attach(9); //Servo attaches to pin 9 (PWM)
  
  //Small break 250 ms
  delay(250);
}

void loop() {

  //Reach the new position
  myServo.write(myServoPosition);
  myServoPosition++;

  //If position > 180 deg, return to '0'
  if(myServoPosition > SERVO_POSITION_MAX){
    
  myServoPosition = SERVO_POSITION_MIN;
  myServo.write(myServoPosition);

  //Delay to return to '0'
  delay(1000);
  }

  //Print the actual position
  Serial.println(myServo.read());

  //Delay 30ms
  delay(30);
}
