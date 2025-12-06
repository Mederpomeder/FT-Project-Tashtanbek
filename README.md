# 🚮 Smart Trash Bin – Intelligent Robotic Waste System

**Developed by:** Dzhanteliev Adilkhan, Sakybaev Meder, Usenkanov Ularbek  
**University:** International Ala-Too University  
**Group:** EEAIR24  
**Date:** 2025  
**Demo Videos** 
---

## 📘 Project Description

The **Smart Trash Bin** is a robotics project combining automation, sensors, servo mechanics, and mobile control.  
The system features:

- Gesture-based automatic lid  
- Bag tightening mechanism  
- Fill-level detection  
- Bluetooth-based smartphone driving module  
- Fully integrated power system with DC-DC buck converter  

This project demonstrates practical robotics, embedded systems design, and IoT communication.

---

## 🎯 Project Goal

To build a fully automated and mobile trash bin that can **open its lid**, **tighten trash bags**, **detect fullness**, and **drive autonomously through Bluetooth control**.

---

## 🧾 Key Features

- ✅ Automatic lid opening (hand wave)  
- ✅ Long-hold gesture detection for bag tightening  
- ✅ Trash fill-level detection using ultrasonic sensor  
- ✅ LED full-capacity indicator  
- ✅ Bluetooth remote-controlled movement  
- ✅ 4-wheel drive platform  
- ✅ Stable power via XL4015E1 buck converter  

---

## 🎯 Project Objectives AND Requirements

| Objective                                   | Status          |
|---------------------------------------------|-----------------|
| Automatic lid system                        | ✅ Complete     |
| Gesture detection (short / long)            | ✅ Implemented  |
| 4-servo tightening system                    | ✅ Working      |
| Fill-level ultrasonic measurement            | ✅ Functional   |
| LED indicator                                | ✅ Added        |
| Bluetooth driving module                     | ✅ Completed    |
| Motor driver setup                           | ✅ Stable       |
| DC-DC power converter integration            | ✅ Solved issue |
| Dual Arduino setup                           | ✅ Used         |
| Wiring + hardware assembly                   | ✅ Done         |

---

## ⚙️ System Functionalities

### 1️⃣ 🔄 Automatic Lid Control  
- **Short hand wave** → Lid opens via servo motor.  
- Triggered by **Ultrasonic Sensor #1**.  

### 2️⃣ 🔧 Bag Tightening Mechanism  
- **Holding your hand above the sensor** (long gesture) activates:  
  - 4 internal servos that **release elastic tension**  
  - The trash bag tightens automatically  

### 3️⃣ 📏 Fill-Level Detection  
- **Ultrasonic Sensor #2** measures distance inside the bin  
- If ≤ **10 cm**, the bin is considered full  
- LED indicator turns **ON**  

### 4️⃣ 📱 Bluetooth Driving System  
- Controlled via smartphone app through HC-06 module  
- Movement includes:  
  - Forward  
  - Backward  
  - Left  
  - Right  
  - Stop  
- Driven by **L293D motor driver** + **4 DC motors**  

---

## 🔌 Hardware Components

### 🧩 Trash Bin Unit Components

| Component                                      | Quantity | Purpose |
|------------------------------------------------|---------:|---------|
| Arduino Uno                                    | 1 | Main controller |
| Breadboard                                     | 1 | Wiring platform |
| Ultrasonic HC-SR04 sensors                     | 2 | Lid gesture + fill-level |
| Servo motors                                   | 5 | Lid (1), Bag system (4) |
| LED                                            | 1 | Bin full indicator |
| Resistor                                       | 1 | LED protection |
| XL4015E1 DC-DC Buck Converter 75W 5A           | 1 | Stable 5V power |
| Battery pack (8V)                              | 1 | Power source |
| Jumper wires                                   | Many | Connections |

---

### 🧩 Driving Platform Components

| Component                | Quantity | Purpose |
|--------------------------|---------:|---------|
| Arduino Uno              | 1 | Motor control |
| Bluetooth HC-06 module   | 1 | Wireless control |
| L293D motor driver       | 1 | Controls motors |
| DC Yellow Gear Motors    | 4 | Drive wheels |
| Wheels                   | 4 | Movement |
| Battery pack (8V)        | 1 | Power |

---

## ⚡ Power System & Issues

We had major issues with unstable power when using:

- 5 servo motors  
- 4 DC motors  
- 2 ultrasonic sensors  
- Bluetooth module  

This caused resets and low-voltage failures.

### ✅ Solution  
We installed a **XL4015E1 DC-DC buck converter**, delivering a stable **5V, up to 5A**, resolving overheating and power drops.

---

## 📂 Project Functional Overview

### ✨ 10 Key Features of the Smart Trash Bin

| # | Feature | Description |
|--:|---------|-------------|
| 1 | 🚪 Automatic Lid | Opens with short hand gesture |
| 2 | ✋ Long Gesture Mode | Activates 4-servo bag tightening system |
| 3 | 📏 Fill-Level Detection | Ultrasonic sensor triggers LED at ≤10 cm |
| 4 | 💡 LED Indicator | Shows full bin |
| 5 | 📱 Bluetooth Control | HC-06 smartphone control |
| 6 | 🚗 4-Wheel Drive | Movement in all directions |
| 7 | 🔋 Power Regulation | Stable 5V via XL4015E1 |
| 8 | 🔧 Multi-Servo Mechanics | 1 lid servo + 4 tightening servos |
| 9 | 🧠 Dual-Arduino Architecture | Separate controllers for trash system & driving |
|10| ⚙️ Modular Electronics | Easy to modify and expand |

---

## 🛠️ System Architecture (Overview)

### Sensors:
- Ultrasonic #1 → Gesture detection  
- Ultrasonic #2 → Trash level measurement  

### Actuators:
- 1 servo → Lid  
- 4 servos → Tightening system  
- 4 DC motors → Driving  

### Controllers:
- Arduino Uno #1 → Trash bin logic  
- Arduino Uno #2 → Driving control  

### Communication:
- HC-06 Bluetooth module  

### Power:
- Batteries (8V)  
- DC-DC converter → regulated 5V  

---

## 📄 Example Sensor Logic (Pseudo):

```text
if distance < 20cm AND gesture duration < 1s:
    open lid

if distance < 20cm AND gesture duration >= 1s:
    activate tightening servos

if inner_distance <= 10cm:
    turn LED on
