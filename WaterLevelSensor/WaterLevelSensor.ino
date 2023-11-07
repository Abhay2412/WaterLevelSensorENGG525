#include <TM1637Display.h>

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

// Module connection pins (Digital Pins)
#define CLK systemClockPinA 
#define DIO systemClockPinB

// Create display object of type TM1637Display
TM1637Display display(CLK, DIO);

// Sensor pins
#define sensorPower 7
#define sensorPin A5

// Value for storing water level
int val = 0;

// Declare pins to which LEDs are connected
int redLED = 2;
int yellowLED = 3;
int greenLED = 4;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  
  // Set LED pins as an OUTPUT
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Initialize the display
  display.setBrightness(0x0f); // Set the brightness level (0x00 to 0x0f)
  display.clear(); // Clear the display

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
    display.clear();
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
  else if (level > 0 && level <= 99) {
    Serial.println("Water Level: Low");
    display.showNumberDec(1); // Display 1 for low level
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  else if (level >= 100 && level <= 150) { // Corrected the condition here
    Serial.println("Water Level: Medium");
    display.showNumberDec(2); // Display 2 for medium level
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else if (level > 155) {
    Serial.println("Water Level: High");
    display.showNumberDec(3); // Display 3 for high level
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
  delay(1000); // Wait for a second before reading again
}

// Function to get the reading from the water level sensor
int readSensor() {
  digitalWrite(sensorPower, HIGH); // Turn on the sensor
  delay(10); // Wait a bit for sensor to stabilize
  val = analogRead(sensorPin); // Read the sensor value
  digitalWrite(sensorPower, LOW); // Turn off the sensor
  Serial.print("Sensor value: ");
  Serial.println(val);

  delay(1000);
  return val;
}
