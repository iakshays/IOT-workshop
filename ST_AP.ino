//#include <ESP8266WiFi.h>
  
#define WIFI_SSID "IOTAsp"
#define WIFI_PASS "1234567890"
 
// Set AP credentials
#define AP_SSID "ESP-Hotspot"
#define AP_PASS "magic-world"
  
void setup() {
  // Setup serial port
  Serial.begin(115200);
  Serial.println();

  WiFi.softAP(AP_SSID, AP_PASS);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  Serial.println("Access point Created!");
  
  Serial.println("Connecting to Wi-Fi name: ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(700);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  
}
  
void loop() {
}
