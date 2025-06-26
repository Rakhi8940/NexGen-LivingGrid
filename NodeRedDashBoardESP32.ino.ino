#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 15          // GPIO where DHT11 is connected
#define DHTTYPE DHT11      // Define the type of DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Define the pins for the sensors
const int irPin = 25;         // IR receiver pin
const int waterLevelPin = 32; // Water level sensor pin
const int ldrPin = 33;        // LDR pin
const int rainSensorPin = 34; // Rain sensor pin

// Define WiFi credentials
const char* ssid = "WiFi-4-U!";
const char* password = "Sachin740062$@";
const char* mqtt_server = "broker.emqx.io";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
  // Initialize the DHT sensor
  dht.begin();
  
  // Set the sensor pins as input
  pinMode(irPin, INPUT);
  pinMode(waterLevelPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(rainSensorPin, INPUT);

  // Connect to WiFi
  setup_wifi();
  
  // Set MQTT server
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  // Reconnect to MQTT broker
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  // Read sensor values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int rainState = digitalRead(rainSensorPin);
  int waterLevelState = digitalRead(waterLevelPin);
  int irValue = analogRead(irPin);
  int ldrValue = analogRead(ldrPin);

  // Print sensor data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Rain Status: ");
  Serial.println(rainState == HIGH ? "Rain Detected" : "No Rain Detected");

  Serial.print("Water Level Status: ");
  Serial.println(waterLevelState == HIGH ? "Medium Amount of water" : "Medium Amount of Water");

  Serial.print("Parking Status: ");
  Serial.println(irValue > 1000 ? "Car is Parked" : "Car is Parked");

  Serial.print("Door Status: ");
  Serial.println(irValue > 1000 ? "Door Opened" : "Door Opened");

  Serial.print("Light Intensity: ");
  Serial.println(ldrValue);

  Serial.print("System Status: ");
  Serial.println(irValue > 1000 ? "System is Working" : "System is Working");
  
  // Publish sensor data to MQTT broker
  publishSensorData("temperature", temperature);
  publishSensorData("humidity", humidity);
  publishSensorData("ldrValue", ldrValue);
  publishSensorData("waterLevelState", waterLevelState);
  publishSensorData("irValue", irValue);
  publishSensorData("rainState", rainState);
  publishSensorData("irValue", irValue);
  publishSensorData("irValue", irValue);
  
  // Wait before next reading
  delay(2000);
}

void publishSensorData(const char* topic, float value) {
  char msg[50];
  dtostrf(value, 6, 2, msg);  // Convert float to string with 2 decimal places
  client.publish(topic, msg);
}
