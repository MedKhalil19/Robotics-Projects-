# 🤖 Stewart Platform - 6 DOF Parallel Robot

## 📌 Project Overview

This project presents the design, simulation, and realization of a **6 Degrees of Freedom (6-DOF) Stewart Platform**, a parallel robotic mechanism capable of performing precise spatial movements through coordinated control of six linear actuators.

The platform uses six independent **Firgelli Filt0805 linear actuators** to control the position and orientation of the moving platform.

The project combines multiple engineering disciplines, including:

- Mechanical design
- Electrical architecture
- Actuator integration
- Robot kinematics
- MATLAB simulation
- Prototype development

The objective is to design and validate a complete mechatronic system capable of generating controlled translations and rotations along the X, Y, and Z axes.

---

# 🎯 Project Objectives

The main objectives of this project are:

- Design a complete Stewart Platform mechanism
- Model the mechanical structure
- Develop the electrical architecture
- Control six linear actuators simultaneously
- Simulate platform movements using MATLAB
- Validate different platform positions with the final prototype

---

# ⚙️ System Description

A Stewart Platform is a parallel robotic mechanism composed of:

- A fixed base
- A moving platform
- Six adjustable linear actuators connecting both platforms

By changing the length of each actuator, the moving platform can achieve:

### Translation movements

- Forward / Backward
- Left / Right
- Up / Down

### Rotation movements

- Roll
- Pitch
- Yaw

The coordinated movement of the six actuators allows accurate positioning and orientation control.

---

# 🔩 Mechanical Design

The mechanical structure was designed to provide:

- Stable platform movement
- Proper actuator placement
- Rigid mechanical connections
- Accurate motion transmission

The design includes:

- Fixed base
- Moving platform
- Actuator mounting points
- Mechanical joints

## Mechanical Design Files

```
Mechanical Design/
```

This folder contains:

- CAD models
- Mechanical drawings
- Assembly views

---

# ⚡ Electrical Architecture

The electrical system is responsible for controlling the six linear actuators and providing the required power and control signals.

Main components:

- Six Firgelli Filt0805 linear actuators
- Motor control electronics
- Power supply system
- Control interface

## Electrical Architecture Files

```
Electrical Architecture/
```

This folder contains:

- Electrical diagrams
- System architecture
- Connection details

---

# 🔌 Electrical Design

The electrical design focuses on the integration of:

- Actuator drivers
- Power distribution
- Control electronics
- Communication between components

## Electrical Design Files

```
Electrical Design/
```

---

# 🧮 MATLAB Simulation

MATLAB was used to model and simulate the Stewart Platform behavior.

The simulation includes:

- Robot geometry definition
- Forward and inverse kinematics
- Actuator length calculation
- Platform position control
- Movement visualization

The simulation validates the ability of the platform to reach different orientations and positions before implementing the physical prototype.

## MATLAB Files

```
MATLAB Simulation/
```

---

# 📷 Results & Prototype

The final results demonstrate different Stewart Platform positions achieved through actuator coordination.

The results folder contains:

```
Results/
│
├── Right Position
├── Left Position
├── Forward Position
├── Backward Position
└── Simulation Video
```

## Tested Positions

The prototype was tested in several configurations:

### ➡️ Right Position

Images showing the platform tilted toward the right side.

### ⬅️ Left Position

Images showing the platform tilted toward the left side.

### ⬆️ Forward Position

Images showing forward platform movement.

### ⬇️ Backward Position

Images showing backward platform movement.

---

# 🎥 Simulation & Prototype Demonstration

The repository includes a final simulation video demonstrating the Stewart Platform movement and validation of the implemented model.

---

# 🧰 Technologies Used

## Mechanical Design

- Solidworks

## Robotics & Simulation

- MATLAB
- Robotics Modeling
- Kinematic Analysis

## Hardware

- 6 × Firgelli Filt0805 Linear Actuators
- 6 × TB6612FNG
- Power Supply System
- ESP32 38 Pins
- ESP32 Expansion Board
- MPU 6050
- Alimentation à découpage
- Module LM2596S
- Module XL4016

## Engineering Fields

- Mechatronics
- Robotics
- Control Systems
- Embedded Systems

---

# 🧠 Skills Demonstrated

This project demonstrates experience in:

- Parallel robotics
- Stewart Platform kinematics
- Mechanical design
- Electrical integration
- Actuator control
- MATLAB simulation
- Mechatronic system development
- Prototype validation

---

# 🚀 Future Improvements

Possible future developments:

- Integrate IMU feedback
- Implement closed-loop control
- Develop a dedicated controller board
- Add joystick or remote control interface
- Improve positioning accuracy

---

# 👨‍💻 Author

**Khlifi Med Khalil**

Mechatronics Engineering Graduate

Interested in:

- Robotics
- Embedded Systems
- IoT
- Artificial Intelligence
- Control Systems
- Mechanical Design
