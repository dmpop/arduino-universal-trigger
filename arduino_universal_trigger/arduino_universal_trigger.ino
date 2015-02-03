/*
MUPOMAT -- Multipurpose Optomechanical Arduino Trigger
Released under the GPLv3 license. 2015, Dmitri Popov
https://github.com/dmpop/arduino-trigger-platform
*/

#include <multiCameraIrControl.h> // import the multiCameraIrControl library
Nikon D90(11); // specify the camera model
 
const int statusPin = 5; // status LED pin
const int cameraPin = 9; // camera pin
const int flashPin = 13; // flash pin
const int buttonPin = 7; // push button pin
const int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the LDR
int buttonState = 0; // Variable for reading the push button status

void setup()
{
  pinMode(statusPin, OUTPUT);
  pinMode(cameraPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  //Start Serial port
  Serial.begin(9600);        // start serial for output
}

void loop()
{
  buttonState = digitalRead(buttonPin);// read button state
  // if it is, the buttonState is pressed:
  if (buttonState == HIGH) {
    D90.shutterNow(); // trigger the shutter  
    digitalWrite(cameraPin, HIGH);
    digitalWrite(statusPin, HIGH);
    digitalWrite(flashPin, HIGH);
    delay(10);
  } else {
    digitalWrite(cameraPin, LOW);
    digitalWrite(statusPin, LOW);
    digitalWrite(flashPin, LOW);
  }
  
  sensorValue = analogRead(sensorPin); // read the value from the LDR:   
  if(sensorValue>950){ // you might need to adjust the default 950 value for better results
    D90.shutterNow(); // trigger the shutter
    digitalWrite(cameraPin, HIGH);
    digitalWrite(statusPin, HIGH);
    digitalWrite(flashPin, HIGH);
    delay(10);
  } else {
    digitalWrite(cameraPin, LOW);
    digitalWrite(statusPin, LOW);
    digitalWrite(flashPin, LOW);
  }
  
  // For DEBUGGING - Print out sensor data, (un)comment the lines below
  //Serial.print(sensorValue, DEC); // print the value (0 to 1024)
  //Serial.println(""); // print carriage return  
  //delay(500);  
}
