
#define BLYNK_TEMPLATE_ID "TMPL6TcQrvZ-"
#define BLYNK_DEVICE_NAME "WEATHER STATION"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"

#include "DHT.h"
#define DHTPIN D2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float t, h;

void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature();  
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
}

void setup()
{
  Serial.begin(9600);
  dht.begin();
  BlynkEdgent.begin();
  delay(2000); 
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run(); // Initiates SimpleTimer
}
