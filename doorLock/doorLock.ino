//Julian Gardner, Abyel Romero
//Final Project - CSCI 4287
//Edited 2020-04-26

//Requires HC-SR04 library - find at www.elegoo.com
#include "SR04.h"
//Also requires Stepper library - find at www.elegoo.com and find documentation at http://www.arduino.cc/en/Reference/Stepper
#include <Stepper.h>

//Function prototypes
void lock();
void unlock();

//Pin constants
const int trigPin = 12;
const int echoPin = 11;
const int motor1N1Pin = 7;
const int motor1N2Pin = 6;
const int motor1N3Pin = 5;
const int motor1N4Pin = 4;

//Other constants
const int unlockDistance = 13; //Maximum distance, in cm, to unlock door
const int motorRPM = 10; //RPM of the stepper motor
const int stepsPerRevolution = 2048; //Number of steps per revolution
const int stepsNeeded = 1024; //Number of steps to lock/unlock door - PLEASE CHANGE THIS DURING TESTING
const int delayamt = 1000; //Delay between unlocking and locking

//Objects
SR04 sensorObject = SR04(echoPin, trigPin);
Stepper stepperObject(stepsPerRevolution, motor1N1Pin, motor1N3Pin, motor1N2Pin, motor1N4Pin);

//Global variables
long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //for testing
  stepperObject.setSpeed(motorRPM);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensorObject.Distance();
  if (distance < unlockDistance)
  {
    unlock();
    delay(delayamt); //wait for the user to get in the door and close it
    lock();
  }
}

void unlock()
{
  stepperObject.step(stepsNeeded);
}

void lock()
{
  stepperObject.step(-stepsNeeded);
}
