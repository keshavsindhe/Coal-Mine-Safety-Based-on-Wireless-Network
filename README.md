# Coal-Mine-Safety-Based-on-Wireless-Network
Embedded System Project

# 🦺 Coal Mine Safety Monitoring System (LoRa-Based Wireless Network)

This project is a *Coal Mine Safety System* designed to monitor and alert hazardous environmental conditions in underground mines using a *wireless LoRa network*.  
It ensures worker safety by continuously sensing air quality, temperature, humidity, and fire presence — transmitting this data wirelessly to a surface monitoring unit for real-time monitoring and alerting.

---

## ⚙ Project Overview

The system is divided into *two main parts*:

### 🔹 Transmitter Unit (Underground Section)
- *NodeMCU (ESP8266)* acts as the main controller.
- Collects real-time data from sensors (gas, temperature, humidity, flame).
- Sends sensor data wirelessly via the *LoRa transmitter module*.
- Activates *buzzer* for local alerts when unsafe conditions are detected.

### 🔹 Receiver Unit (Monitoring Station)
- *Arduino UNO* receives sensor data through the *LoRa receiver module*.
- Displays live data on an *OLED screen*.
- Activates *buzzer alert* when unsafe readings are received.

---

## 🧩 Features

- 🔥 *Gas Detection (MQ-135)* – Detects harmful gases such as methane or carbon monoxide  
- 🌡 *Temperature & Humidity (DHT11)* – Monitors ambient heat and moisture levels  
- 🔥 *Flame Sensor* – Detects presence of fire or sparks  
- 📡 *LoRa Wireless Communication* – Long-range, low-power data transmission  
- 🚨 *Buzzer Alerts* – Local and remote alerts for dangerous conditions  
- 🖥 *OLED Display (Receiver)* – Real-time display of sensor readings and alert messages  

---

## 🛠 Hardware Components

### *Transmitter Side*
| Component | Function |
|------------|-----------|
| NodeMCU (ESP8266) | Main controller for data acquisition |
| MQ-135 Gas Sensor | Detects harmful gases |
| DHT11 Sensor | Measures temperature and humidity |
| Flame Sensor | Detects fire or spark |
| LoRa Transmitter | Sends data wirelessly |
| Buzzer | Local warning alert |
| Power Supply (5V) | Power source |

### *Receiver Side*
| Component | Function |
|------------|-----------|
| Arduino UNO | Main controller for data reception |
| LoRa Receiver | Receives wireless data |
| OLED Display | Shows real-time readings |
| Buzzer | Alerts in unsafe conditions |
| Power Supply (5V) | Power source |

---

## 💻 Software & Tools

- *Embedded C / C++*
- *Arduino IDE*
- *LoRa Libraries (RadioHead / LMIC)*
- *Serial Monitor / OLED Display*
- *Proteus (for simulation)*

---

## 🚀 Working Principle

1. *Transmitter unit* continuously collects sensor data.  
2. The *NodeMCU* processes readings and compares them with safety thresholds.  
3. If a hazardous condition occurs:
   - The *transmitter buzzer* activates.
   - Data is sent via *LoRa* to the receiver unit.  
4. The *receiver unit (Arduino UNO)* displays data on the OLED screen.  
5. If any parameter exceeds safe limits, the *receiver buzzer* alerts the monitoring personnel.

---

## 📊 Sample Output

| Parameter | Normal Value | Alert Value | Action |
|------------|---------------|--------------|--------|
| Gas Level | < 200 ppm | > 300 ppm | Activate buzzer |
| Temperature | < 40°C | > 45°C | Activate buzzer |
| Flame Detected | No | Yes | Activate buzzer |

---

## 🔋 Advantages

- Long-range wireless communication with *LoRa*
- Reliable and low power consumption
- Real-time underground monitoring
- Dual alert system (mine site + monitoring room)
- Scalable and cost-effective design

---

## 📈 Future Enhancements

- Integration with *IoT dashboards* (e.g., Thingspeak, Blynk) for cloud-based monitoring  
- Add *GPS* for worker tracking  
- Include *battery backup* and *solar charging* for uninterrupted operation  

---

## 👨‍🔧 Developed By

*Keshav S. Shinde*  
*JNN College of Engineering, Shivamogga*  
*Department of Electronics and Communication Engineering (2025 Batch)*  

---

## 📜 License
This project is open-source — feel free to use or modify it for educational purposes.



