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
  else if (level > 0 && level <= 99) {
    Serial.println("Water Level: Low");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  else if (level >= 100 && level <= 150) { // Corrected the condition here
    Serial.println("Water Level: Medium");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else if (level > 155) {
    Serial.println("Water Level: High");
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