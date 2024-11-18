#include <ESP8266WiFi.h>

// Pin assignments for relays and buttons
#define RELAY1_PIN D0
#define RELAY2_PIN D2

#define BUTTON1_PIN D1
#define BUTTON2_PIN D5

// HTML page for the web server
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <title>ESP8266 Load Control</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            margin: 0;
            padding: 0;
            background-color: #f9f9f9;
        }
        h1 {
            background-color: #007BFF;
            color: white;
            padding: 15px;
            margin: 0;
            font-size: 55px;
        }
        .button-container {
            display: flex;
            flex-direction: column;
            gap: 30px;
            max-width: 600px;
            margin: 0 auto;
            padding-top: 60px;
        }
        .btn-row {
            display: flex;
            justify-content: space-between;
            gap: 20px;
        }
        button {
            width: 100%;
            padding: 35px;
            font-size: 40px;
            color: #fff;
            background-color: #007BFF;
            border: none;
            border-radius: 10px;
            cursor: pointer;
            transition: background-color 0.2s;
        }
        button.danger {
            background-color: #dc3545;
        }
        button:hover {
            background-color: #0056b3;
        }
        button:active {
            background-color: #004080;
        }
        button.danger:hover {
            background-color: #b6202f;
        }
    </style>
</head>
<body>
    <h1>Control Two Loads</h1>
    <div class="button-container">
        <div class="btn-row">
            <button onclick="sendRequest('relay1On')">Load 1 ON</button>
            <button onclick="sendRequest('relay1Off')" class="danger">Load 1 OFF</button>
        </div>
        <div class="btn-row">
            <button onclick="sendRequest('relay2On')">Load 2 ON</button>
            <button onclick="sendRequest('relay2Off')" class="danger">Load 2 OFF</button>
        </div>
    </div>
    <script>
        function sendRequest(action) {
            fetch('/' + action)
                .then(response => response.text())
                .then(data => console.log(data))
                .catch(error => console.error('Error:', error));
        }
    </script>
</body>
</html>
)rawliteral";

// Your Wi-Fi credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Web server instance
WiFiServer server(80);

// Variables to track relay states
bool relay1State = false;
bool relay2State = false;

void setup() {
  Serial.begin(9600);

  // Set relay pins as output
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Set button pins as input with pullup resistors
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  // Set default relay states (OFF)
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  Serial.println("Connecting to Wi-Fi...");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the web server
  server.begin();
}

void loop() {
  // Web server functionality
  WiFiClient client = server.available();
  if (client) {
    while (!client.available()) delay(1);

    String request = client.readStringUntil('\r');
    Serial.println(request);

    if (request.indexOf("/relay1On") != -1) {
      digitalWrite(RELAY1_PIN, LOW);
      relay1State = true;
    } else if (request.indexOf("/relay1Off") != -1) {
      digitalWrite(RELAY1_PIN, HIGH);
      relay1State = false;
    } else if (request.indexOf("/relay2On") != -1) {
      digitalWrite(RELAY2_PIN, LOW);
      relay2State = true;
    } else if (request.indexOf("/relay2Off") != -1) {
      digitalWrite(RELAY2_PIN, HIGH);
      relay2State = false;
    }

    client.flush();
    client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    client.print(htmlPage);
    client.stop();
  }

  // Physical button functionality
  static bool lastButton1State = HIGH;
  static bool lastButton2State = HIGH;

  bool currentButton1State = digitalRead(BUTTON1_PIN);
  bool currentButton2State = digitalRead(BUTTON2_PIN);

  if (currentButton1State != lastButton1State) {
    digitalWrite(RELAY1_PIN, currentButton1State);
    lastButton1State = currentButton1State;
  }

  if (currentButton2State != lastButton2State) {
    digitalWrite(RELAY2_PIN, currentButton2State);
    lastButton2State = currentButton2State;
  }

  delay(50); // Debounce delay
}
