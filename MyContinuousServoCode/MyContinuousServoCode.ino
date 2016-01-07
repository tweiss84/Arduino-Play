//Parallax Continuous Rotation Servo  Combinted with Distance Sensor
//http://learn.parallax.com/KickStart/900-00008 
// Three pin Distance sensor
// https://www.parallax.com/product/28015
#include <Servo.h> 
 
Servo servoLeft; // create servo object to control a servo 
Servo servoRight;

int bitToSet = 8;  // In case you want to control from the command prompt
const int pingPin = 11;  // distance sensor Pin
int C;
String isGoing = "stop"; // current state of servos

void setup() {
  
    Serial.begin(9600);
    Serial.println("reset");
    servoLeft.attach(9); // attaches the servo on pin 9 to the servo object 8 & 9 make two servos
    servoRight.attach(8);
    turnDirection("stop"); // default pulse to hold still 1500 (Calibration on servos to center on this frequency) 
    delay(1000);
    turnDirection("forward");
}

void loop() {
  
    if (Serial.available() > 0) {
        bitToSet = Serial.read() - 48;
        Serial.println(bitToSet);
    }

    if (bitToSet == 1) {
        turnDirection("left");
    } else if (bitToSet == 2) {
        turnDirection("right");
    } else if (bitToSet == 3) {
        turnDirection("stop");
    }
    bitToSet = 0;  // reset the bit so it doesn't keep firing
    
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  C =  digitalRead(duration);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);  // to serially print the data
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println(" - ");

  if (inches < 12)
  {
    if(isGoing != "right")
    {
      isGoing = "right";
      turnDirection("right");  // Derek Zoolander: "I’m not an ambi-turner. I can't turn left."
    }
  }
  else
  {
     if(isGoing != "forward")
      {
        isGoing = "forward";
        turnDirection("forward");
      }
  }  
}

void turnDirection(String direction) {

    if (direction == "left") {
        Serial.println("left");
        servoLeft.writeMicroseconds(1800);
        servoRight.writeMicroseconds(1800);
    }
    if (direction == "right") {
        Serial.println("right");
        servoLeft.writeMicroseconds(1300);
        servoRight.writeMicroseconds(1300);
    }
    if (direction == "stop") {
        Serial.println("stop");
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
    }
    if (direction == "forward") {
        Serial.println("forward");
        servoLeft.writeMicroseconds(1800);
        servoRight.writeMicroseconds(1300);
    }

}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
