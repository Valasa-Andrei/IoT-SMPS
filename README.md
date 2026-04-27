## IoT-SMPS
A smart monitoring system for plants
## 1. Project Description
    The Smart Garden Environmental Monitoring System is an IoT-based project designed to track the health of indoor plants in real-time. By utilizing an ESP32 microcontroller, the system monitors four critical variables: air temperature, humidity, ambient light intensity, and soil moisture levels. This data is processed locally and streamed to a high-fidelity visualizer in VS Code (Teleplot), allowing for immediate data analysis and intervention. The goal of the project is to provide a low-power, scalable solution for precision agriculture and home automation.

## 2. Pre-requisites
# Hardware Components
    ESP32 DevKit V1 (30-pin): The core microcontroller with Wi-Fi and Bluetooth capabilities. Specification Datasheet https://documentation.espressif.com/esp32_datasheet_en.pdf
    
    DHT22 (AM2302): High-accuracy digital temperature and humidity sensor. Specification Datasheet https://www.edn.com/am2302-dht22-datasheet/
    
    BH1750 (GY-302): Digital Ambient Light Sensor with I2C interface. Specification Datasheet https://www.handsontec.com/dataspecs/sensor/BH1750%20Light%20Sensor.pdf
    
    Soil Moisture Sensor Module: Resistive/Capacitive probe for measuring earth humidity. Specification Datasheet https://www.electrokit.com/upload/product/41015/41015738/41015738_-_Soil_Moisture_Sensor.pdf
    
    MB102 Breadboard & Jumper Wires: For solderless circuit assembly. 

# Software Components
    Visual Studio Code: The primary Integrated Development Environment (IDE).
    
    PlatformIO IDE Extension: Professional extension for IoT development. 
    

## 3. Schematics
    
    A. Power Rail
    Connect the 3V3 pin on your ESP32 to the red (+) rail of your breadboard.
    
    Connect the GND pin on your ESP32 to the blue (-) rail of your breadboard.
    
    B. BH1750 (Light Sensor - I2C)
    VCC → 3.3V Rail
    
    GND → GND Rail
    
    SCL → GPIO 22 (labeled D22)
    
    SDA → GPIO 21 (labeled D21)
    
    C. DHT22 (Temp/Hum - Digital)
    VCC → 3.3V Rail
    
    GND → GND Rail
    
    Data → GPIO 4 (labeled D4)
    
    Note: If your DHT22 is the bare sensor (4 pins), you need a 10k resistor between VCC and Data. If it's on a small PCB (3 pins), the resistor is likely already built-in.
    
    D. Soil Moisture (Analog)
    VCC → 3.3V Rail
    
    GND → GND Rail
    
    AO (Analog Out) → GPIO 34 (labeled VP or 34)

## 4. Setup and Build
    Hardware Assembly: Seat the ESP32 in the center of the breadboard. Connect the power rails (3.3V and GND). Plug in the DHT22 and Soil sensor using separate rows. Connect the BH1750 to the I2C pins (21/22).
    
    VS Code Configuration: Open VS Code and create a new PlatformIO Project. Select "Espressif ESP32 Dev Module" as the board and "Arduino" as the framework.
    
    Library Installation: In platformio.ini, add the following dependencies:

    Ini, TOML
    lib_deps =
        adafruit/DHT sensor library
        adafruit/Adafruit Unified Sensor
        claws/BH1750
    Pin Definitions: Ensure DHTPIN is set to 4 and SOIL_PIN is set to 34 in your code.

## 5. Running
    Compilation: Click the Checkmark icon in the PlatformIO toolbar to verify the code is error-free.
    
    Deployment: Connect the ESP32 via USB and click the Right Arrow icon to upload the firmware.
    
    Initialization: Open the Serial Monitor (plug icon) to ensure sensors are initializing correctly.
    
