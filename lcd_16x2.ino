  
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>      
LiquidCrystal_I2C lcd(0x27,16,2);  //for 16x2 lcd display



void setup() {
    // initiate the lcd                  
 lcd.backlight(); 
 Serial.begin(9600);
 lcd.setCursor(2,0);
 lcd.print("Gas leakage"); 
 lcd.setCursor(4,1);
 lcd.print("Detector"); 
 delay(3500);    
 lcd.clear(); 
}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("Gas Level:");
  lcd.setCursor(10,0);
  lcd.setCursor(12,0);
  lcd.print("%");
  

  delay(500);
  lcd.clear();
}
