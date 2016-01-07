int DO = 2; //Pin for Digital Output - DO
int DA = A0; // Pin for Analog Output - AO
int threshold = 47; //Set minimum threshold for LED lit
int sensorvalue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {

  sensorvalue = analogRead(DA);  //Read the analog value
//  Serial.print("Analog: ");
//  Serial.print(sensorvalue);  //Print the analog value
//  Serial.println(" ");
//  delay(5);
  if (sensorvalue >= threshold) { //Compare analog value with threshold
      digitalWrite(13, HIGH);
      Serial.print("***** Volume HIT : ");
//      Serial.print(sensorvalue);  //Print the analog value
//      Serial.print("  ");
//      Serial.print("Digital: ");
//      Serial.print(digitalRead(DO));  //Print the digital value
//      Serial.println(" ");
    } else {
//      Serial.println(" ");
      digitalWrite(13, LOW);
    }
}
