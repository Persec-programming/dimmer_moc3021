  #include <ESP8266WiFi.h>
#include <PubSubClient.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager


const char* mqttServer = "hairdresser.cloudmqtt.com";
const int mqttPort = 17476;
const char* mqttUser = "hgggziwm";
const char* mqttPassword = "iqTMOPkwnDIw";

String topic  = "public";
String  ssid;
String macId;

const byte ledPin1 = 5;
const byte ledPin2 = 4;
const byte ledPin3 = 0;
const byte ledPin4 = 2 ;


WiFiClient espClient;
PubSubClient client(espClient);



void setup() {

  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT); // Initialize the LED pin as an output
  pinMode(ledPin2, OUTPUT); // Initialize the LED pin as an output
  pinMode(ledPin3, OUTPUT); // Initialize the LED pin as an output
  pinMode(ledPin4, OUTPUT); // Initialize the LED pin as an output
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;

  //exit after config instead of connecting
  wifiManager.setBreakAfterConfig(true);

  //reset settings - for testing
  //wifiManager.resetSettings();


  //tries to connect to last known settings
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP" with password "password"
  //and goes into a blocking loop awaiting configuration
  if (!wifiManager.autoConnect("AutoConnectAP", "password")) {
    Serial.println("failed to connect, we should reset as see if it connects");
    delay(3000);
    ESP.reset();
    delay(5000);

  }

  //if you get here you have connected to the WiFi
  Serial.println("NOW ESP8266 IS CONECTING TO WIFI  :)");
  ssid = wifiManager.getSSID();
  Serial.println(ssid);
  Serial.println("LOCAL IP ADDRESS");
  Serial.println(WiFi.localIP());
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
}

void reconnect(){
  
  while (!client.connected()) {
    Serial.println("CONNECTING TO  MQTT...");

    if (client.connect("DimmerEsp8266",mqttUser,mqttPassword)) {

      Serial.println("CONNECTED TO MQTT");

    } else {

      Serial.print("MQTT failed with state ");
      Serial.print(client.state());
      delay(5000);

    }
  }

 

  client.subscribe("dimmer");
  
  
  }

void callback(char* top, byte* message, unsigned int length) {
  Serial.println("Message arrived on topic: ");
  Serial.println(top);
  Serial.println(". Message: ");
  String messageTemp;
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

Serial.println(messageTemp);

  
  String topic = String((char*)top);
  



  }



String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}




String ipAddress() {
  return WiFi.localIP().toString();
}

void loop() {
  if(!client.connected()){

reconnect();
    }else{
    
       }
if(!client.loop()){
    }else{
    
    }
}








    
