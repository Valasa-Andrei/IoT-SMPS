# IoT-SMPS
A smart monitoring system for plants
1. Project Description
The Smart Garden Environmental Monitoring System is an IoT-based project designed to track the health of indoor plants in real-time. By utilizing an ESP32 microcontroller, the system monitors four critical variables: air temperature, humidity, ambient light intensity, and soil moisture levels. This data is processed locally and streamed to a high-fidelity visualizer in VS Code (Teleplot), allowing for immediate data analysis and intervention. The goal of the project is to provide a low-power, scalable solution for precision agriculture and home automation.

2. Pre-requisites
Hardware Components
ESP32 DevKit V1 (30-pin): The core microcontroller with Wi-Fi and Bluetooth capabilities. Specification Datasheet

DHT22 (AM2302): High-accuracy digital temperature and humidity sensor. Specification Datasheet

BH1750 (GY-302): Digital Ambient Light Sensor with I2C interface. Specification Datasheet

Soil Moisture Sensor Module: Resistive/Capacitive probe for measuring earth humidity. Specification Datasheet

MB102 Breadboard & Jumper Wires: For solderless circuit assembly.

Software Components
Visual Studio Code: The primary Integrated Development Environment (IDE). Download Page

PlatformIO IDE Extension: Professional extension for IoT development. Marketplace Link

Teleplot Extension: Real-time telemetry visualizer for VS Code. Marketplace Link

3. Schematics
To get the 10 points here, you should use Fritzing to draw your diagram. Ensure you follow these "Excellent" rules:

Color Code your Wires: Red for 3.3V, Black for GND, Yellow/Blue for I2C (SCL/SDA), and Green for Data (DHT/Soil).

Avoid Overlaps: Do not let wires cross over the top of sensors; route them around components.

Wiring Checklist:

DHT22: VCC → 3.3V | GND → GND | DATA → GPIO 4.

BH1750: VCC → 3.3V | GND → GND | SCL → GPIO 22 | SDA → GPIO 21.

Soil Sensor: VCC → 3.3V (or 5V/VIN for better range) | GND → GND | AO → GPIO 34 (VP).

4. Setup and Build
Hardware Assembly: Seat the ESP32 in the center of the breadboard. Connect the power rails (3.3V and GND). Plug in the DHT22 and Soil sensor using separate rows. Connect the BH1750 to the I2C pins (21/22).

VS Code Configuration: Open VS Code and create a new PlatformIO Project. Select "Espressif ESP32 Dev Module" as the board and "Arduino" as the framework.

Library Installation: In platformio.ini, add the following dependencies:

Ini, TOML
lib_deps =
    adafruit/DHT sensor library
    adafruit/Adafruit Unified Sensor
    claws/BH1750
Pin Definitions: Ensure DHTPIN is set to 4 and SOIL_PIN is set to 34 in your code.

5. Running
Compilation: Click the Checkmark icon in the PlatformIO toolbar to verify the code is error-free.

Deployment: Connect the ESP32 via USB and click the Right Arrow icon to upload the firmware.

Initialization: Open the Serial Monitor (plug icon) to ensure sensors are initializing correctly.

Visualization: Close the Serial Monitor and start a Teleplot session. Connect to the appropriate COM port at 115200 baud. Select the variables (Temperature, Humidity, Light, Soil) to view the live charts.
