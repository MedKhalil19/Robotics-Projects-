# 🤖 Fighter Robot (Combat Robot)

## 📌 Project Overview
This project focuses on the **design and programming of a combat (fighter) robot** using the **original hoverboard (overboard) motherboard**, which is based on an **STM32 microcontroller**. Instead of designing a custom control board from scratch, the existing hoverboard controller was **reprogrammed and adapted** to meet the specific requirements of a combat robot.

The robot integrates **motor control, power management, and remote operation via an RC controller**, delivering high torque, fast response, and robustness suitable for competitive robotic environments.

---

## 🧠 Hoverboard Controller Adaptation
The hoverboard motherboard originally designed for self-balancing operation was **repurposed for robotic combat use**:

- The **original STM32 firmware was modified** to disable self-balancing logic  
- Custom code was developed to allow **direct motor speed and direction control**  
- RC controller inputs were integrated to replace hoverboard sensor feedback  
- Safety and power constraints were adjusted to handle aggressive maneuvers  

This process required **low-level embedded programming**, signal analysis, and a deep understanding of the hoverboard control architecture.

---

## 🚀 Key Features
- ⚔️ **Combat-oriented robotic platform**
- 🛞 **Hoverboard motors & wheels** as the main drive system
- 🎮 **Remote control via RC transmitter**
- ⚡ **STM32-based hoverboard motherboard**
- 🔄 **Custom-modified motor control firmware**
- 🔋 **Integrated power management**
- 🛠️ **Robust and modular mechanical design**

---

## 🧠 System Architecture

### 🔧 Hardware Components
- Hoverboard motherboard (STM32-based)  
- Hoverboard motors and wheels  
- RC receiver & transmitter  
- Power management and regulation circuits  
- Combat robot chassis  

### 💻 Software Components
- Modified STM32 firmware for robotic control  
- Motor control algorithms adapted from hoverboard logic  
- RC signal decoding and command mapping  
- STM32Cube tools for flashing and debugging  

---

## ⚙️ How It Works
1. RC controller sends motion commands  
2. RC receiver decodes and forwards signals to the STM32  
3. Custom firmware processes RC inputs  
4. Modified motor control logic drives hoverboard motors  
5. Power management ensures stable operation under high load  

---

## ⚠️ Project Note – Code Availability
Due to an unexpected **data loss on the development laptop**, a significant portion of the original firmware and experimental code was deleted.  
Currently, **only three core source files remain available** in this repository.

Despite this limitation, the remaining files reflect the **core control logic and system adaptation**, and the project documentation explains the overall architecture and development approach.
