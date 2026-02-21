# Escaper – Autonomous Obstacle Avoidance

## Project Overview
The **Escaper** is an autonomous robotic system designed to navigate independently while maintaining a precise safety buffer from obstacles.  

The project focuses on implementing a real-time PI control loop to manage velocity and proximity using ultrasonic feedback for environmental sensing.

Developed as part of the **Product Dynamics** course at **Delft University of Technology** (2021 - 2022).

---

## Technical Specifications

- **Microcontroller:** Arduino UNO / Seeeduino Lotus  
- **Control Algorithm:** PI (Proportional-Integral) Controller  
- **Actuators:** Dual DC Motors driven by a Cytron MDD3A H-Bridge  
- **Sensors:**  
  - HC-SR04 Ultrasonic Sensor (Proximity)  
  - Optical Encoders (Velocity feedback)  
- **Language:** C++  
- **Environment:** VS Code + PlatformIO  

---

## Control Parameters

The controller constants were determined using the Ziegler-Nichols tuning method:

- **Target Distance:** 20.0 cm  
- **Proportional Gain (Kp):** 0.18  
- **Integral Gain (Ki):** 0.864  
- **Output Constraint:** 50 – 255 PWM (ensures motor torque and prevents stalling)  
- **Sampling Rate:** 200 ms  

### Control Law

The PI controller is implemented as:


$$u(t) = K_p e(t) + K_i \int e(t) dt$$


Where:
- `e(t)` = distance error  
- `u(t)` = motor control signal  

---

## Performance Results

| Scenario | Observation |
|----------|------------|
| **Approach** | Smooth deceleration as the 20 cm threshold is reached |
| **Stationary** | Stable hold at target distance with minimal oscillation |
| **Obstacle Removal** | Linear acceleration back to cruising speed |

---

## Project Structure

```text
include/
├── robot_config.h       # Hardware pinout and calibrated constants
├── pid_controller.h     # PI control class definition
└── motor_control.h      # Actuator interface definition

src/
├── main.cpp             # System state machine and timing loop
├── pid_controller.cpp   # Mathematical implementation of PI logic
└── motor_control.cpp    # Directional and PWM actuation logic
```

---

# Installation & Usage

## Prerequisites

- VS Code with the PlatformIO IDE extension or Arduino IDE
- C++ compiler (integrated with PlatformIO)  
- Arduino Uno or compatible hardware  

---

## Setup

Clone the repository:

```bash
git clone https://github.com/Dhando70/escaper-product-dynamics.git
```

Open the project:

1. Launch VS Code  
2. Open the project folder  
3. PlatformIO will automatically initialize the environment  

---

## Deployment

### Build
Click the ✓ icon in the bottom status bar in VS Code to compile the code.

### Upload
Connect the Arduino via USB and click the → icon to flash the firmware.

### Monitor
Open the Serial Monitor (9600 baud) to view real-time distance and PI controller data.
