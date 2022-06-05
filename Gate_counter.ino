#define BLYNK_TEMPLATE_ID "TMPLtNXxemSD"
#define BLYNK_DEVICE_NAME "Gate counter"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"


 #define sensor D3
 int counter = 0;

void sendSensor()
{
  if(digitalRead(D3)==LOW){
    counter++;
    Serial.println(counter);
    Blynk.virtualWrite(V1, counter);
    delay(1000);
  
}}

void setup()
{
  Serial.begin(9600);
 pinMode(sensor , INPUT);
  BlynkEdgent.begin();
  delay(2000); 
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run(); // Initiates SimpleTimer
}
