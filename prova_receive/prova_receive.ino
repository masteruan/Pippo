/*
 * Receive the data on the channell
 */


#include <Wire.h>
#define CHANNELL 11 // 8

void setup() {
  Wire.begin(CHANNELL);         // join i2c bus with address #??
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  Serial.println("Go...");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  int x = Wire.read();  // receive byte as an integer
  Serial.println(x);    // print the integer
  if (x==1){
    digitalWrite(13, HIGH);
  }
  if (x==0){
    digitalWrite(13, LOW);
  }
}

