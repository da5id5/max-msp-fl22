// C++ code
//
const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into
int val[6]; //array 6 sensors total

void setup()
{
  Serial.begin(9600); // initialize serial communication   
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as an output:
}

void loop()
{
 //read analog inputs one by one and send them to max
  for(int i = 0; i < 6; i++){
   val[i] = analogRead(i);
   Serial.print(val[i]);
   Serial.print(" ");
}

 Serial.println(); // sent to MaxMSP
 delay(10 );

   // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
}
}