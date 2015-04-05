/*
Flex Sensor and LEDs created by ScottC on 23rd May 2011
updated on 16/05/2012.
http://arduinobasics.blogspot.com/2011/05/arduino-uno-flex-sensor-and-leds.html

-----------------------------------------------------*/

//Flex Sensor Pin (flexPin)
//the analog pin the Flex Sensor is connected to
int flexPin = 0;  
                  
void setup() {
  for (int i=8; i<14; i++){
    pinMode(i, OUTPUT); //sets the led pins 8 to 13 to output
  }
}

void loop(){
 //Ensure to turn off ALL LEDs before continuing 
 for (int i=8; i<14; i++){
    digitalWrite(i, LOW); 
  }
 
 /* Read the flex Level 
  Adjust the value 130 to 275 to span 8 to 13
  The values 130 and 275 may need to be widened to suit 
  the minimum and maximum flex levels being read by the 
  Analog pin */
 int flexReading = map(analogRead(flexPin), 130, 225, 8, 13); 
         
// Make sure the value does not go beyond 8 or 13
 int LEDnum = constrain(flexReading, 8, 13); 
 
/*Call the blink function: this will turn the LED on for 10 milliseconds, and keep it
  off for only 1 millisecond. You can change the blink rate by changing these values,
  however, I want a quick response time when the flex sensor bends, hence the small 
  values. LEDnum determines which LED gets turned on.*/
 blink(LEDnum, 10,1);
}

// The blink function - used to turn the LEDs on and off
void blink(int LEDPin, int onTime, int offTime){
  // Turn the LED on                                         
 digitalWrite(LEDPin, HIGH);  
 
  // Delay so that you can see the LED go On.
 delay(onTime);
 
  // Turn the LED Off                                         
  digitalWrite(LEDPin, LOW);  
 
 // Increase this Delay if you want to see an actual blinking effect.
  delay(offTime);
}
