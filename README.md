# 🚮 Smart Trash Bin – Intelligent Robotic Waste System

<img width="500" height="668" alt="image" src="https://github.com/user-attachments/assets/9cd59295-96c1-4841-ad5e-6d6a24facac7" />

<img width="481" height="725" alt="image" src="https://github.com/user-attachments/assets/f7a0352d-ae7e-49cd-b9b1-630e1385f7cf" />



**Developed by:** Dzhanteliev Adilkhan, Sakybaev Meder, Usenkanov Ularbek  
**University:** International Ala-Too University  
**Group:** EEAIR24  
**Date:** October 2025 - December 2025  
**Demo Videos:** https://drive.google.com/drive/folders/1tPDS4UWKTIs76ECvT-CGCigkDOEJd5cr?usp=sharing
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

You can watch the demo video here: https://drive.google.com/drive/folders/1tPDS4UWKTIs76ECvT-CGCigkDOEJd5cr?usp=sharing

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

## 🧠 Example Sensor Logic

### 🔹 1. **Distance Measurement**
```
long getDistance(trig, echo) {
  trigger LOW → HIGH (10 µs pulse)
  pulseIn(echo, HIGH) → duration
  distance_cm = duration / 58
}

```

### 🔹 2. Fullness Detection
```
if (innerDist > 0 AND innerDist <= BIN_FULL_DISTANCE):
    LED_FULL = ON
else:
    LED_FULL = OFF
```

### 🔹 3. Hand Gesture Detection Logic
```
if (handDetected AND NOT handPresent AND NOT sequenceRunning):
    handPresent = true
    handStartTime = millis()

if (handDetected AND handPresent AND NOT sequenceRunning):
    holdTime = millis() - handStartTime

    if (holdTime >= HOLD_THRESHOLD):
        sequenceRunning = true

        lidOpen()
        wait 2 sec
        runQuartet()     // 4 servos tighten bag
        wait 1 sec
        lidClose()

        sequenceRunning = false
        handPresent = false
........
```

### 🔹 4. Short Gesture (hand removed before 3 sec)
```
if (NOT handDetected AND handPresent AND NOT sequenceRunning):
    holdTime = millis() - handStartTime
    handPresent = false

    if (holdTime < HOLD_THRESHOLD):
        sequenceRunning = true
        lidOpen()
        wait 700 ms
        lidClose()
        sequenceRunning = false
```

### 🔹 5. Driving System Bluetooth Commands
```
if command == 'F': motors FORWARD
if command == 'B': motors BACKWARD
if command == 'L': turn LEFT
if command == 'R': turn RIGHT
if command == 'G': forward-left (left motor slow)
if command == 'H': forward-right (right motor slow)
if command == 'I': backward-left
if command == 'J': backward-right
if command == 'S': STOP motors
if command == 'Y': buzzer beep sequence
if command == 'X': LED ON
if command == 'x': LED OFF
if command is '0'–'9': change speed
```


### Some pictures of the project assembly process:


<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/9328ab6f-812e-49f1-b6ed-277613c155c2" />


<img width="1280" height="960" alt="image" src="https://github.com/user-attachments/assets/4ca9ac84-5166-4d0a-af3c-e4d9bd5a9a5b" />


<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/a23b8f01-4fcf-4fc8-accd-389f1fbc1a9a" />


<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/4e036401-6d64-4096-9a2f-bb682b768814" />


<img width="1280" height="960" alt="image" src="https://github.com/user-attachments/assets/4f8b4899-79d4-44a3-8b36-ceb2f82a044f" />
