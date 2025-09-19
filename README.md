# Wi-Fi Controlled RC Car Using Relay Modules and ESP8266 (No Motor Driver)

## Project Overview

This project demonstrates how to build a Wi-Fi controlled RC car using relay modules and an ESP8266 (NodeMCU) board without using a motor driver IC. The relay modules switch power to four DC geared motors allowing forward, backward, left, and right control via Wi-Fi.

The car is powered by 18650 lithium batteries for the motors and a separate LiPo battery for the ESP8266. This simple design is perfect for hobbyists and STEM learners.

---

## Features

- Wi-Fi control via ESP8266
- Uses relay modules instead of motor driver ICs
- Controls four DC motors
- Powered by 18650 and LiPo batteries
- Optional buzzer for alerts
- Easy to customize and build

---

## Components Needed

- 4 x DC geared motors with wheels  
- 2 x 2-Channel relay modules (5V)  
- ESP8266 Wi-Fi board (NodeMCU or equivalent)  
- 2 x 18650 batteries (motors power)  
- 1 x 3.7V LiPo battery (ESP8266 power)  
- Buzzer (optional)  
- Connecting wires and chassis  

---

## Circuit Diagram and Connections

![Circuit Diagram](./Picsart_25-09-19_12-59-56-734.jpeg)

- Connect 18650 batteries positive to relay COM terminals.
- Connect motors to NO terminals of relays.
- Relay IN pins to ESP8266 GPIO (e.g., D1-D4).
- ESP8266 powered by LiPo battery separately.
- Optional buzzer connected to a free GPIO.

---

## How It Works

The ESP8266 controls relay modules via GPIO pins. Activating a relay connects power to the motor, controlling its direction. This setup replaces the need for motor driver ICs with simple electromechanical relays.

---

## Installation & Usage

1. Clone this repo:https://github.com/jeyaram1023/rc-car-using-relay
2. Open and upload the code to your ESP8266 using Arduino IDE.
3. Wire the hardware as described.
4. Power the batteries and use the web interface or app to control the car.

---

## Project Code

Access full code:  
https://docs.google.com/document/d/1cR2K0z_ACOTWtbaDDuuuR3UR6KRlCj-7MwINL5lo7d0/edit?usp=sharing

---

## Learn More

Detailed tutorial and explanation:  
https://jeyaramb.blogspot.com/2025/09/wi-fi-controlled-rc-car-using-relay.html

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file.

---

## Acknowledgments

Thanks to the maker community and open source projects for inspiration.

