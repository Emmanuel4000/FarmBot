 🌱 DIY FarmBot – Smart Automated Farming Robot

This repository contains the Arduino code and design files for our DIY FarmBot, an ongoing project to automate farming tasks like planting, watering, and soil monitoring.  

---

 🚀 Features
- Multi-axis movement (X, Y, Z).
- Automated watering system.
- Soil moisture monitoring (future addition).
- Expandable for planting, weeding, and data collection.

---

 🛠️ Hardware Requirements
- Arduino Uno + CNC Shield
- NEMA17 stepper motors
- TB6600 stepper motor drivers (connected through CNC Shield)
- Power supply (12V–24V)
- Linear rails or 3D-printed frame
- Water pump + relay module
- Soil moisture sensor (optional)
- Jumper wires & connectors

---

 🔌 Wiring Setup
The motors are driven via an Arduino CNC Shield and TB6600 stepper drivers:

- CNC Shield STEP → TB6600 PUL+
- CNC Shield DIR → TB6600 DIR+
- CNC Shield EN → TB6600 ENA+
- TB6600 negative pins (PUL-, DIR-, ENA-) → GND
- TB6600 motor outputs (A+, A-, B+, B-) → NEMA17 motor coils
- TB6600 VCC (12–24V) → external power supply
- Arduino Uno powered via USB or 12V barrel jack

(See wiring diagram in `docs/wiring_diagram.png`)

---

 💻 Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- Libraries:
  - `AccelStepper.h`
  - `EEPROM.h`

---

 📂 Project Structure
