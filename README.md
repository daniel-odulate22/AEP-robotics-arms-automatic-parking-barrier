# Automatic Parking Barrier Using Arduino

## Project Overview

This project demonstrates an automatic parking barrier using an Arduino Uno, an HC-SR04 ultrasonic distance sensor, and a positional servo motor.

It was developed for Assignment C of the Aurora Robotics Educators Program (AEP), Robotic Arms Track.

## Problem Statement

Manually operated parking barriers can require an attendant to open and close the gate. This project demonstrates a simple system that detects a nearby object and automatically operates a barrier.

## Components

- Arduino Uno R3
- HC-SR04 ultrasonic distance sensor
- Positional micro servo motor
- Jumper wires
- Tinkercad Circuits simulator

## How It Works

1. The HC-SR04 sends an ultrasonic pulse.
2. The sensor detects the returning echo.
3. The Arduino calculates the distance to the detected object.
4. If the object is within 15 cm, the servo moves to 90 degrees to open the barrier.
5. If the object is farther away, the servo returns to 0 degrees to close the barrier.
6. If no echo is detected, the system keeps the barrier closed.
7. Distance readings and gate status are displayed in the Serial Monitor.

## Pin Connections

| Component | Arduino Pin |
|---|---|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Servo signal | D6 |
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |

The servo and Arduino must share a common ground. A physical implementation must also use a suitable power supply for the servo.

## Testing

The system should be tested with objects placed at different distances from the sensor.

Expected behaviour:

- Within 15 cm: barrier opens.
- Beyond 15 cm: barrier closes.
- No echo detected: barrier remains closed.

## Concepts Demonstrated

- Ultrasonic distance measurement
- Arduino digital input and output
- Conditional statements
- Servo motor control
- Sensor-based automation
- Microcontroller decision-making

## Limitations and Future Improvements

This is a basic simulation, not a complete real-world parking system. It does not verify vehicle identity or include safety mechanisms for preventing a gate from closing on an obstruction.

Possible improvements include adding a warning light, a second safety sensor, and a timed gate-closing mechanism.

## Author

Daniel Alexander Odulate

Aurora Robotics Educators Program (AEP) 2026  
Robotic arms Track
