
#define BLYNK_TEMPLATE_ID "TMPLHOfD47hk"
#define BLYNK_DEVICE_NAME "Home automation"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
//#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"


void setup()
{
  pinMode(D5,OUTPUT);
  pinMode(D6,INPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();

  
    /*if(digitalRead(D6)==HIGH){
    digitalWrite(D5,HIGH);
    }*/

}


BLYNK_WRITE(V0)
{
 if(param.asInt()==1){
  digitalWrite(D5, HIGH);
 }
 if(param.asInt()==0){
  digitalWrite(D5,LOW);

  }

  
}

/*BLYNK_CONNECTED(){
  Blynk.syncVirtual(V0);
}*/
