# ESP8266 Load Control Without Internet (Wifi Mode)

This project demonstrates how to control two electrical loads using an ESP8266 microcontroller. It features a web-based interface for wireless control and physical buttons for manual operation. The ESP8266 connects to an existing Wi-Fi network to host a web server.

## Features

-   **Web-Based Control**: Manage two loads via an interactive web interface.
-   **Manual Button Control**: Use physical buttons to toggle the loads.
-   **Wi-Fi Connectivity**: Connects to your Wi-Fi network for remote access.
-   **Relay Management**: Each load is connected to a relay for switching.

## Prerequisites

Before uploading the code, make sure you have the following:

-   **Hardware**:
    -   ESP8266 board
    -   Two relays for controlling loads
    -   Two push buttons
    -   Resistors (if needed for button pull-up)
    -   Power supply for the ESP8266
-   **Software**:
    -   [Arduino IDE](https://www.arduino.cc/en/software) with ESP8266 board support installed.

## Pin Configuration

| ESP8266 Pin | Function        |
| ----------- | --------------- |
| D0          | Relay 1 Control |
| D2          | Relay 2 Control |
| D1          | Button 1 Input  |
| D5          | Button 2 Input  |

## How to Use

1. **Setup Wi-Fi Credentials**:
   Replace `Your_SSID` and `Your_PASSWORD` in the code with your Wi-Fi network's SSID and password.

2. **Upload the Code**:

    - Connect your ESP8266 to your computer.
    - Select the correct board and port in the Arduino IDE.
    - Upload the code.

3. **Circuit Connection**:

    - Connect the relays and buttons to the specified pins.
    - Ensure proper isolation when connecting high-voltage loads.

4. **Access the Web Interface**:

    - After the ESP8266 connects to your Wi-Fi, it prints the IP address in the serial monitor.
    - Open the IP address in a web browser to access the control panel.

5. **Control the Loads**:
    - Use the web interface buttons to turn the loads on or off.
    - Alternatively, use the physical buttons for manual control.

## Web Interface

The web interface includes the following features:

-   **Load 1 ON/OFF**: Controls Relay 1.
-   **Load 2 ON/OFF**: Controls Relay 2.
