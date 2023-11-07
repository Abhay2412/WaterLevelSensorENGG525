#include <TM1637Display.h>
/* Change these values based on your calibration values */
int lowerThreshold = 420;
int upperThreshold = 520;

// Sensor pins
#define sensorPower 7
#define sensorPin A0

// Value for storing water level
int val = 0;

// Declare pins to which LEDs are connected
int redLED = 2;
int yellowLED = 3;
int greenLED = 4;

//Digital 7 System clock top pins
int systemClockPinA = 22; 
int systemClockPinB = 23; 
int systemClockPinC = 24; 
int systemClockPinD = 25; 
int systemClockPinE = 26; 
int systemClockPinF = 27;

//Digital 7 System clock bottom pins
int systemClockPinG = 30; 
int systemClockPinH = 31; 
int systemClockPinI = 32; 
int systemClockPinJ = 33; 
int systemClockPinK = 34; 
int systemClockPinL = 35; 


void setup() {
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  
  // Set LED pins as an OUTPUT
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Set the 7 System Clock pins as an OUTPUT
  pinMode(systemClockPinA, OUTPUT);     
  pinMode(systemClockPinB, OUTPUT);     
  pinMode(systemClockPinC, OUTPUT);     
  pinMode(systemClockPinD, OUTPUT);     
  pinMode(systemClockPinE, OUTPUT);     
  pinMode(systemClockPinF, OUTPUT);     
  pinMode(systemClockPinG, OUTPUT);   
  pinMode(systemClockPinH, OUTPUT);  
  pinMode(systemClockPinI, OUTPUT);  
  pinMode(systemClockPinJ, OUTPUT);  
  pinMode(systemClockPinK, OUTPUT); 
  pinMode(systemClockPinL, OUTPUT); 

  // Initially turn off all LEDs
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  int level = readSensor();

  if (level == 0) {
    Serial.println("Water Level: Empty");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
  else if (level > 0 && level <= lowerThreshold) {
    Serial.println("Water Level: Low");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

  }
  else if (level > lowerThreshold && level <= upperThreshold) {
    Serial.println("Water Level: Medium");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else if (level > upperThreshold) {
    Serial.println("Water Level: High");
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(systemClockPinA, HIGH);
    digitalWrite(systemClockPinB, LOW);
    digitalWrite(systemClockPinC, LOW);
    digitalWrite(systemClockPinD, LOW); 
  }
  delay(1000);
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return val;
}
