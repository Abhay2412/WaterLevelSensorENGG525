# Water Level Sensor 
![Arduino](https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

ENGG 525 - Engineering Entrepreneurship - Fall 2023 Assignment #3 

## Innovation
The water sensor system innovation is in the residential flood prevention, particularly vital for cities like Calgary, where the unique geographical and climatic conditions contribute to a higher propensity for water-induced calamities. Drawing on the latest environmental data, Calgary has faced significant flooding, with the 2013 flood being one of the most devastating natural disasters in Canadian history, inflicting damages exceeding $5 billion CA. Our sensor system introduces a pioneering approach to early water detection, leveraging real-time monitoring and immediate visual alerts to forewarn homeowners.

## Techincal Planning
![Schematic](WaterLevelSensorSchematic.png)
The schematic developed in EasyEDA forms the basis for the hardware aspect of the technical plan, which would be complemented by software development for reading the sensor data, interpreting it, and controlling the outputs.

## Final Design
![FinalDesign1](FinalDesign1.jpg)

![FinalDesign2](FinalDesign2.jpg)

![FinalDesign3](FinalDesign3.jpg)

## Components List using ELEGOO Starter Kit
1. Quantity: 1, Name: Water Level Detection Sensor Module 
2. Quantity: 1, Name: Red LED
3. Quantity: 1, Name: Green LED
4. Quantity: 1, Name: Yellow LED
5. Quantity: 1, Name: MEGA Controller Board  
6. Quantity: 1, Name: 830 Tie-Points Breadboard
7. Quantity: 7, Name: Breadboard Jumper Wires
8. Quantity: 3, Name: Female-to-male Dupoint Wires 
9. Quantity: 3, Name: 220 Ω ohm Resistors

## Testing Plans

### Unit Testing
We verified the accuracy of the water level readings from the sensor by submerging the sensor in water at known levels and comparing the sensor readings to the actual levels. Sensor readings should match the actual water levels within the acceptable margin of error. For the LED functionality ensure each LED (Red, Yellow, Green) lights up as expected. Write unit tests to power each LED individually through the Arduino pins. Each LED should illuminate when its corresponding pin is set HIGH. 

### System Testing
We validated the complete system's operation in a real-world scenario by placing the sensor in a controlled environment where we varied the water levels and recorded the system's response. The testing result was that it was able to accurately reflect the changes in water levels with the appropriate LED indications.

## Documentation
For each of the tests we documented the type of testing we performed, results, and any deviations from expected outcomes. We also included steps for replicating the tests, conditions under which the tests were performed, and any relevant environmental factors.
