// Example 45.1 - tronixstuff.com - CC by-sa-nc
// Connect Ping))) signal pin to Arduino digital 8
int signal=8;
int lightBuzz = 9;
int distance;
unsigned long pulseduration=0;
void setup()
{
 pinMode(signal, OUTPUT);
 pinMode(lightBuzz,OUTPUT);
 Serial.begin(9600);
}
void measureDistance()
{
 // set pin as output so we can send a pulse
 pinMode(signal, OUTPUT);
// set output to LOW
 digitalWrite(signal, LOW);
 delayMicroseconds(1);

 // now send the 5uS pulse out to activate Ping)))
 digitalWrite(signal, HIGH);
 delayMicroseconds(1);
 digitalWrite(signal, LOW);

 // now we need to change the digital pin
 // to input to read the incoming pulse
 pinMode(signal, INPUT);

 // finally, measure the length of the incoming pulse
 pulseduration=pulseIn(signal, HIGH);
}

void lightEmUp(){
  tone(lightBuzz,740,1);
}

void loop()
{
 // get the raw measurement data from Ping)))
 measureDistance();

 // divide the pulse length by half
 pulseduration=pulseduration/2; 

 // now convert to centimetres. We're metric here people...
 distance = int(pulseduration/29);
 if(distance<91){
   lightEmUp();
 }
 // Display on serial monitor
 Serial.print("Distance - ");
 Serial.print(distance);
 Serial.println(" cm");
 delay(50);
}
