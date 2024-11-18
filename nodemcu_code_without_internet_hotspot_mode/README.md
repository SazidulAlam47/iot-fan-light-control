# ESP8266 Load Control Without Internet (Hotspot Mode)

This project allows you to control two electrical loads using an ESP8266 microcontroller. The loads can be switched on/off via a web interface or physical buttons. The ESP8266 hosts a local web server and acts as an access point, enabling wireless control without the need for an external Wi-Fi network.

## Features

-   **Web Interface**: Control loads via a simple HTML interface.
-   **Physical Buttons**: Use physical buttons to toggle the loads.
-   **Standalone Operation**: The ESP8266 acts as an access point with its own Wi-Fi network.
-   **DNS Redirection**: Automatically redirects devices to the control interface.

## Hardware Requirements

-   ESP8266 board
-   Two relays for load control
-   Two push buttons
-   Resistors (if needed for button pull-up)
-   Power supply for ESP8266

## Pin Connection

| Pin | Function | Description     |
| --- | -------- | --------------- |
| D0  | Relay 1  | Controls Load 1 |
| D2  | Relay 2  | Controls Load 2 |
| D1  | Button 1 | Toggles Relay 1 |
| D5  | Button 2 | Toggles Relay 2 |

## Connection Diagram

![Connection Diagram](connection_diagram.png)

Ensure that relays are connected to external loads appropriately and take necessary precautions when dealing with high-voltage circuits.

## Software Setup

1. **Upload Code**:
    - Install the Arduino IDE and configure it for ESP8266.
    - Copy the provided code into the Arduino IDE.
    - Connect your ESP8266 board to the computer.
    - Select the appropriate board and COM port in the Arduino IDE.
    - Upload the code to the ESP8266.

## Usage

1. **Power On**:

    - Once powered, the ESP8266 creates a Wi-Fi network named `ESP8266 Load Control`.
    - The default password is `12345678`.

2. **Connect to Wi-Fi**:

    - Use a device (e.g., smartphone or laptop) to connect to the Wi-Fi network.

3. **Access the Web Interface**:

    - Open a browser and navigate to any URL (e.g., `http://192.168.4.1`).
    - You will be redirected to the control interface.

4. **Control Loads**:

    - Use the buttons in the web interface to turn the loads on/off.

5. **Physical Buttons**:
    - Press the physical buttons to toggle the corresponding relays.

### Web Interface

The interface includes buttons to control two loads with clear ON and OFF options for each load.
