
#define VIN A0 // define the Arduino pin A0 as voltage input (V in)
const float VCC   = 5.0;// supply voltage is from 4.5 to 5.5V. Normally 5V.
const int model = 0;   // enter the model number (see below)

float cutOffLimit = 0.2;// set the current which below that value, doesn't matter. Or set 0.5


float sensitivity[] ={
          0.185,// for ACS712ELCTR-05B-T 0.185 default
          0.100,// for ACS712ELCTR-20A-T
          0.066// for ACS712ELCTR-30A-T
     
         }; 


const float QOV =   0.5 * VCC;// set quiescent Output voltage of 0.5V
float voltage;// internal variable for voltage

void setup() {

    Serial.begin(9600);
    Serial.println("ACS712 Current Sensor");
}

void loop() {
  
  float voltage_raw =   (5.0 / 1023.0)* analogRead(VIN);// Read the voltage from sensor
  voltage =  voltage_raw - QOV + 0.012 ;// 0.000 is a value to make voltage zero when there is no current
  float current = voltage / sensitivity[model];
 
  if(abs(current) > cutOffLimit ){

    Serial.print("I: ");
    Serial.print(current,2); // print the current with 2 decimal places
    Serial.println("A");
  }else{
    Serial.println("No Current");
  }
  delay(500);
}
