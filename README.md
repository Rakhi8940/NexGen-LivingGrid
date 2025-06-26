<p align="center">
  <img src="https://github.com/user-attachments/assets/a450a461-d077-4ba7-9911-294ad933c427" width="900" alt="NexGen LivingGrid Banner" style="margin: 12px 0; border-radius: 18px; background: #fff; box-shadow: 0 4px 16px rgba(0,0,0,0.12); padding: 0;">
</p>

# 🏡 NexGen LivingGrid

**NexGen LivingGrid** is a next-generation, cloud-connected smart home platform integrating Node-RED, Blynk IoT, and a wide array of sensors and actuators for seamless automation, monitoring, and control. Built using Arduino Uno, ESP8266, ESP32, and more, it combines two cloud platforms for robust data visualization and remote management.

---

## 🎯 Objective

- Create a feature-rich smart home platform for automation, monitoring, and security.
- Support both remote & local control via Node-RED dashboard and Blynk IoT app.
- Integrate multiple sensors & actuators for intelligent real-world smart actions.
- Store, analyze, and visualize data using multiple cloud services.

---

## 🛠️ Hardware Used

| Component            | Quantity | Purpose                                   |
|----------------------|----------|-------------------------------------------|
| Arduino Uno          | 1        | Central controller                        |
| ESP8266              | 1        | WiFi/cloud communication                  |
| ESP32                | 1        | IoT node/control                          |
| Rain Sensor          | 1        | Rain detection for automations            |
| DHT11 Sensor         | 1+       | Temperature & humidity monitoring         |
| Soil Moisture Sensor | 1+       | Smart irrigation/plant monitoring         |
| Water Level Sensor   | 1        | Tank/water source monitoring              |
| Ultrasonic Sensor    | 1+       | Distance, security, parking               |
| RFID Module          | 1        | Smart access control                      |
| Servo Motors         | 1+       | Automated doors/windows                   |
| IR Sensors           | 1+       | Intruder detection, automation            |
| LDR (Light Sensor)   | 1+       | Smart lighting                            |
| LCD Display          | 1        | Local status/info display                 |
| Relay Module         | 1+       | Control appliances (fan, pump, lights)    |
| LEDs                 | 3+       | Indicators, lighting                      |
| Fan                  | 1        | Smart ventilation/cooling                 |
| Battery/Power        | as needed| Backup power                              |

---

## ☁️ Cloud Platforms

- **Node-RED:** Dashboard, local automations, flows, MQTT/HTTP integration
- **Blynk IoT:** Mobile app for remote control, real-time monitoring, notifications

---

## 🖥️ System Architecture

<p align="center">
  <img src="assets/nexgen_livinggrid_architecture.png" width="700" alt="System Architecture" style="background: #fff; border-radius: 12px; box-shadow: 0 2px 8px rgba(0,0,0,0.10); padding: 16px;">
</p>

---

## 🚦 Key Features

- **Multi-Sensor Monitoring:** Real-time monitoring of temperature, humidity, soil, water level, light, rain, and more.
- **Security:** RFID-based smart access, ultrasonic/IR-based intrusion detection.
- **Smart Controls:** Fan, lights, pump, and appliances via relay (manual/automatic/cloud/app).
- **Automation:** Threshold-based automations (e.g., auto-fan on high temp, pump on low water).
- **Cloud Dashboards:** Node-RED for local web UI, Blynk IoT for mobile dashboard and notifications.
- **Data Logging:** Store and visualize sensor & event data historically.
- **Voice Assistant Integration:** (Optional) Alexa/Google Home via Node-RED.

---

## 📲 Mobile App (Blynk IoT)

- Monitor all sensors in real time
- Get alerts (rain, low water, intrusion detection, etc.)
- Manually control appliances and doors
- View historical data and trends

---

## 🧑‍💻 Node-RED Dashboard

- Real-time web dashboard for any device
- Visualize all sensor data and control devices
- Simple drag-and-drop flow editing for custom automations

---

## 🔌 Example Use Cases

- **Auto-lighting:** Lights automatically control based on LDR and presence.
- **Smart Fan:** Fan turns ON/OFF based on temperature thresholds.
- **Irrigation:** Soil moisture triggers water pump and logs activity.
- **Security:** Door unlocks with RFID, alerts on IR/ultrasonic detection.
- **Rain Alert:** Rain sensor triggers window action or sends app alert.

---

## 📁 Project Structure

```
NexGen-LivingGrid/
├── assets/
│   ├── nexgen_livinggrid_banner.png
│   ├── nexgen_livinggrid_architecture.png
├── Arduino/
│   ├── main_controller.ino
│   ├── esp8266_node.ino
│   ├── esp32_node.ino
├── NodeRED/
│   ├── flows.json
├── Blynk/
│   ├── blynk_template.json
├── README.md
└── ...
```

---

## 📝 Getting Started

1. **Assemble all sensors and actuators as per the wiring diagrams.**
2. **Flash Arduino/ESP codes for each node (see Arduino/ folder).**
3. **Set up Node-RED server and import the flows.**
4. **Configure Blynk IoT app with widgets and template.**
5. **Update WiFi, Blynk, and cloud credentials in the code.**
6. **Power up and enjoy your next-gen smart home!**

---

## 🧠 Customization Ideas

- Add Google/Alexa voice integration via Node-RED
- Integrate weather API for smarter automations
- Add a camera/face recognition for enhanced security
- Expand device count and create individual room zones

---

## 📚 Resources

- [Node-RED Docs](https://nodered.org/docs/)
- [Blynk IoT Docs](https://docs.blynk.io/)
- [ESP8266 Guide](https://randomnerdtutorials.com/getting-started-with-esp8266/)
- [ESP32 Guide](https://randomnerdtutorials.com/getting-started-with-esp32/)
- [Arduino Uno Docs](https://docs.arduino.cc/hardware/uno-rev3)
- [Best Practices for IoT Security](https://owasp.org/www-project-internet-of-things/)

---

## 📝 License

MIT License

---

## 👩‍💻 Author

Made with ❤️ by **Rakhi Yadav**

---

*Experience the future of living – with NexGen LivingGrid!*
