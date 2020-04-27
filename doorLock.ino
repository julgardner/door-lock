//Julian Gardner, Abyel Romero
//Final Project - CSCI 4287
//Edited 2020-04-26

//Requires HC-SR04 library - find at www.elegoo.com
#include "SR04.h"

//Function prototypes
void lock();
void unlock();

//Pin constants
const int trigPin = 12;
const int echoPin = 11;
const int unlockDistance = 13; //Maximum distance, in cm, to unlock door

//Objects
SR04 sensorObject = SR04(echoPin, trigPin);

//Global variables
long distance;
bool isLocked;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //for testing
  isLocked = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensorObject.Distance();
  Serial.print(distance); //for testing
  Serial.println("cm"); //for testing
  if ((distance < unlockDistance) && isLocked)
  {
    Serial.println("Unlocking"); //for testing
    unlock();
    isLocked = false;
    delay(25000); //wait for the user to get in the door and close it
    lock();
  }
  delay(1000); //for testing
}

void unlock()
{
  //empty for now
  //TODO motor code
}

void lock()
{
  //empty for now
  //TODO motor code
}
