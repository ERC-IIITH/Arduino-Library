#include <PubSubClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "YOUR_WIFI_AP"; // enter your creds in between quotes
const char* password = "PASSWORD";
const char* mqtt_server = "broker.emqx.io"; // refer this link for other free mqtt clients

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) //message/ instructions to be executed when asked
{
// payload contains the information received in the subscribed channel
  {
  // any function can be used to process the received data. 
  // e.g if payload[0] = '0' ... else ...
  }
  char* msg = "Insert_DATA_HERE";
  client.publish("INSERT_CHANNEL_HERE", msg); // publishes the 'msg 'data to the channel inserted.
  // Duplicate the above line to publish to multiple channels
  // This can be used anywhere once MQTT connection is established.
} //end callback

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "Client:";
    clientId += String(random(0xffff), HEX);//assigning a random client address
    // Attempt to connect

     if (client.connect(clientId.c_str()))
      {
      Serial.println("connected");
     //once connected to MQTT broker,we are subscribing to command 
      client.subscribe("Subscription_Channel"); //channel to be subscribed (enter within quotes)
        // Duplicate the above line to subscribe to multiple channels
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
} 

void setup() {
  Serial.begin(9600);
Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
      Serial.println("WiFi connected");
  client.setServer(mqtt_server, 1883);//mqtt server name and  port
  client.setCallback(callback);//initiate this to send reply when there's data from publisher
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
