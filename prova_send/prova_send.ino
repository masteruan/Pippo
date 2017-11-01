/*
 * Receive the data from serial
 *
 * Write by i2c:
 * Wire begin(); Set the channel for i2c
 * Wire.beingTransmission(??); Declare the transmission channel
 * Wire.write(1); Write the value
 * Wire.endTransmission(); End transmission
 *
 */
#include <Wire.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  Wire.begin();
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  Serial.println("###############");
  Serial.println("You are Welcome");
  Serial.flush();
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    //
    seriale();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
void seriale (){
     if(inputString == "on\n"){
      Wire.beginTransmission(8);
      Wire.write(1);
      Wire.endTransmission();
      Serial.println("...inviato");
    }
    if(inputString == "off\n"){
      Wire.beginTransmission(8);
      Wire.write(0);
      Wire.endTransmission();
      Serial.println("...inviato");
    }
     if(inputString == "onni\n"){
      Wire.beginTransmission(11);
      Wire.write(1);
      Wire.endTransmission();
      Serial.println("...inviato");
    }
    if(inputString == "offi\n"){
      Wire.beginTransmission(11);
      Wire.write(0);
      Wire.endTransmission();
      Serial.println("...inviato");
    }
}

void serialEvent() {
  Serial.flush();
  delay(20);
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
