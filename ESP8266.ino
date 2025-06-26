#define BLYNK_TEMPLATE_ID "TMPL3ZIpsNUKg"
#define BLYNK_TEMPLATE_NAME "IoT Based Home Automation"
#define BLYNK_AUTH_TOKEN "jDqM6tzPu6uLs32Oj4CrFfoLKlsbXgWz"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>  // Include the Blynk library for ESP8266

#define SOIL_MOISTURE_PIN A0   // Analog pin for soil moisture sensor
#define THRESHOLD_MOISTURE 10 // Adjust this value based on your soil moisture sensor readings
#define PUMP_PIN D1  // Digital pin for controlling the pump

char auth[] = BLYNK_AUTH_TOKEN;  // Replace with your Blynk auth token
char ssid[] = "WiFi-4-U!";   // Replace with your WiFi credentials
char pass[] = "Sachin740062$@";

bool isPumpOn = false;  // Variable to track pump status

void sendSensorData()
{
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  Serial.print("Soil Moisture ");
  Serial.println(soilMoisture);
  // Map the analog sensor values to a percentage (0-100)
  int soilMoisturePercentage = map(soilMoisture, 400, 1023, 100, 0);
  Serial.print("Soil Moisture Percentage ");
  Serial.println(soilMoisturePercentage);
  // Send soil moisture data to Blynk

  // Check if the pump should be on based on manual switch or soil moisture level
  if (isPumpOn || soilMoisturePercentage < THRESHOLD_MOISTURE)
  {
    // Turn on the pump
    digitalWrite(PUMP_PIN, HIGH);
    // Check if the pump is turned on automatically (not manually)
    if (!isPumpOn) {
      Serial.println("Soil moisture is below the threshold!");
    }
  }
  else
  {
    // Turn off the pump only if it was not turned on manually
    if (!isPumpOn) {
      digitalWrite(PUMP_PIN, LOW);
    }
  }
}

// Function to handle Blynk button press
BLYNK_WRITE(V1) { // V1 is the virtual pin assigned to the button in the app
  isPumpOn = param.asInt(); // Get the button state (1 for on, 0 for off)
  if (isPumpOn) {
    digitalWrite(PUMP_PIN, HIGH); // Turn pump on
    Serial.println("Pump turned ON manually from Blynk app.");
  } else {
    digitalWrite(PUMP_PIN, LOW); // Turn pump off
    Serial.println("Pump turned OFF manually from Blynk app.");
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT); // Set pump pin as an output

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass); // Initialize Blynk connection
}

void loop()
{
  Blynk.run(); // Handle Blynk connection
  sendSensorData(); // Call the function to send soil moisture data to Blynk
  delay(1000);  // Add a delay to avoid overwhelming the server and slow down the loop
}
