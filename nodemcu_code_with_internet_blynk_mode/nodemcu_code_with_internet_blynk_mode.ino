/***********************************
This code is for a Low level Triger relay
and a switch with digital pin and ground connection with
NodeMCU ESP8266 board
--------------------
in this code
1 is OFF
0 is ON
--------------------
***********************************/
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "your-template-id"  // replace "your-template-id" with you Blynk Template ID
#define BLYNK_TEMPLATE_NAME "your-template-name"  // replace "your-template-name" with you Blynk Template name
#define BLYNK_AUTH_TOKEN "your-auth-token"  // replace "your-auth-token" with you Blynk Automation Token

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

#define relayPin1 D0
#define switchPin1 D1

#define relayPin2 D2
#define switchPin2 D5

bool switchState1 = 0;
bool switchStateOld1 = 0;
bool blynkState1 = 1;
bool blynkStateOld1 = 1;
int eeprom_relay1 = 1;
int eeprom_switch1 = 3;

bool switchState2 = 0;
bool switchStateOld2 = 0;
bool blynkState2 = 1;
bool blynkStateOld2 = 1;
int eeprom_relay2 = 2;
int eeprom_switch2 = 4;

bool isBlynkConnected = 0;

char ssid[] = "your-ssid";  // replace "your-ssid" with your wireless router SSID
char pass[] = "your-password";  // replace "your-password" with your wireless router Password

bool allOff = 0;
bool allOffOld = 0;

BLYNK_WRITE(V0) {
  allOff = param.asInt();
  if (allOff == LOW && allOffOld == HIGH) {
    Serial.println("All-Off-Clicked");
    //turn off relay 1
    digitalWrite(relayPin1, 1);
    Blynk.virtualWrite(V1, 1);
    EEPROM.write(eeprom_relay1, 1);
    blynkStateOld1 = 1;
    //turn off relay 2
    digitalWrite(relayPin2, 1);
    Blynk.virtualWrite(V2, 1);
    EEPROM.write(eeprom_relay2, 1);
    blynkStateOld2 = 1;
    EEPROM.commit(); // Save the data to EEPROM
  }
  allOffOld = allOff;
}

BLYNK_WRITE(V1) {
  blynkState1 = param.asInt();
  if (blynkState1 != blynkStateOld1) {
    Serial.print("blynkClicked1, ");
    Serial.println(blynkState1);
    digitalWrite(relayPin1, blynkState1);
    blynkStateOld1 = blynkState1;
    EEPROM.write(eeprom_relay1, blynkState1);
    EEPROM.commit(); // Save the data to EEPROM
  }
}

BLYNK_WRITE(V2) {
  blynkState2 = param.asInt();
  if (blynkState2 != blynkStateOld2) {
    Serial.print("blynkClicked2, ");
    Serial.println(blynkState2);
    digitalWrite(relayPin2, blynkState2);
    blynkStateOld2 = blynkState2;
    EEPROM.write(eeprom_relay2, blynkState2);
    EEPROM.commit(); // Save the data to EEPROM
  }
}

void setup() {
  EEPROM.begin(10);
  Serial.begin(9600);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  restore_old_states();
  WiFi.begin(ssid, pass);
  Blynk.config(BLYNK_AUTH_TOKEN);
  timer.setInterval(3000L, checkBlynk);  // check if connected to Blynk server every 3 seconds
}

void loop() {

  timer.run();  // Initiates SimpleTimer

  // Check WiFi connected or not
  if (WiFi.status() == WL_CONNECTED) {

    Blynk.run();
    // Check Blynk connected or not
    if (isBlynkConnected) {
      Serial.print("internet connected. IP Address is: ");
      Serial.println(WiFi.localIP());
      with_internet();
    } 
    else {
      Serial.print("connected, no internet. IP Address is: ");
      Serial.println(WiFi.localIP());
      without_internet();
    }
  } 
  else {
    Serial.println("WiFi Not Connected.");
    without_internet();
  }

  delay(300);
}

void restore_old_states(){
  blynkStateOld1 = EEPROM.read(eeprom_relay1);
  blynkStateOld2 = EEPROM.read(eeprom_relay2);
  switchStateOld1 = EEPROM.read(eeprom_switch1);
  switchStateOld2 = EEPROM.read(eeprom_switch2);
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);


  if(switchStateOld1 == 0 && switchState1 == 1){
    digitalWrite(relayPin1, HIGH);  // off the ralay 1
  }
  else if(blynkStateOld1 == 0){
    digitalWrite(relayPin1, LOW); // on the ralay 1
  }
  else{
    digitalWrite(relayPin1, HIGH);  // off the ralay 1
  }


  if(switchStateOld2 == 0 && switchState2 == 2){
    digitalWrite(relayPin2, HIGH);  // off the ralay 2
  }
  else if(blynkStateOld2 == 0){
    digitalWrite(relayPin2, LOW); // on the ralay 2
  }
  else{
    digitalWrite(relayPin2, HIGH);  // off the ralay 2
  }
}

void with_internet() {
  Blynk.virtualWrite(V1, blynkStateOld1);
  Blynk.virtualWrite(V2, blynkStateOld2);

  switchState1 = digitalRead(switchPin1);
  if (switchState1 != switchStateOld1) {
    Serial.print("switchClicked1, ");
    Serial.println(switchState1);
    digitalWrite(relayPin1, switchState1);
    Blynk.virtualWrite(V1, switchState1);
    blynkStateOld1 = switchState1;
    switchStateOld1 = switchState1;
    EEPROM.write(eeprom_relay1, switchState1);
    EEPROM.write(eeprom_switch1, switchState1);
    EEPROM.commit(); // Save the data to EEPROM
  }

  switchState2 = digitalRead(switchPin2);
  if (switchState2 != switchStateOld2) {
    Serial.print("switchClicked2, ");
    Serial.println(switchState2);
    digitalWrite(relayPin2, switchState2);
    Blynk.virtualWrite(V2, switchState2);
    blynkStateOld2 = switchState2;
    switchStateOld2 = switchState2;
    EEPROM.write(eeprom_relay2, switchState2);
    EEPROM.write(eeprom_switch2, switchState2);
    EEPROM.commit(); // Save the data to EEPROM
  }

}

void without_internet() {

  switchState1 = digitalRead(switchPin1);
  if (switchState1 != switchStateOld1) {
    Serial.print("switchClicked1, ");
    Serial.println(switchState1);
    digitalWrite(relayPin1, switchState1);
    blynkStateOld1 = switchState1;
    EEPROM.write(eeprom_relay1, switchState1);
    EEPROM.write(eeprom_switch1, switchState1);
    EEPROM.commit(); // Save the data to EEPROM
  }

  switchState2 = digitalRead(switchPin2);
  if (switchState2 != switchStateOld2) {
    Serial.print("switchClicked2, ");
    Serial.println(switchState2);
    digitalWrite(relayPin2, switchState2);
    blynkStateOld2 = switchState2;
    EEPROM.write(eeprom_relay2, switchState2);
    EEPROM.write(eeprom_switch2, switchState2);
    EEPROM.commit(); // Save the data to EEPROM
  }

  switchStateOld1 = switchState1;
  switchStateOld2 = switchState2;
}

void checkBlynk() {
  isBlynkConnected = Blynk.connected();
}
