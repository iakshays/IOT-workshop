

int offset =20;// set the correction offset value

 
void setup() {

    Serial.begin(9600);
    Serial.println("voltage sensor reading");
}

void loop() {
  
  int volt = analogRead(A1);// read the input
  double voltagenn = map(volt,0,1023, 0, 2500) + offset;// voltage map 0-1023 to 0-2500 and add correction offset
  
  voltagenn /=100;// divide by 100 to get the decimal values
  Serial.println("Voltage: ");
  Serial.print(voltagenn);//print the voltge reading 
  Serial.println("V");
 delay(800);
}
