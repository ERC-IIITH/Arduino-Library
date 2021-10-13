/* Light Intensity using LDR in Lux*/

/* Setup 
   1. Connect one LDR pin to A0
   2. Connect the other pin to Arduino Ground
*/

//constants
int LDRpin = A0;  // select the input pin for LDR
int LDRvalue = 0; // variable to store the value coming from the LDR
int lux = 0;      //to store the intensity of light in 

void setup() {
  //Begin Serial Monitor
  Serial.begin(9600);
}

void loop() {
  
  //Getting the LDR analog value
  LDRvalue = analogRead(LDRpin);
  
  //Using the formula for conversion from analog value to lux
  lux = (512000 / LDRvalue) - 500;

  // Show output on serial monitor
  Serial.print("Intensity: ");
  Serial.print(lux);
  Serial.print(" lux");
}
