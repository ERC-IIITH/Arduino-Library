
#include <LM35.h>


LM35 temp(A0);
 
// Function that will be executed once when connecting or resetting the Arduino
void setup() 
{
  // start the Serial communication 
  Serial.begin(9600); 
}

void loop() 
{
  Serial.print("Temp - ");  //Send a text to serial
  Serial.print(temp.cel()); //It gets the temperature in celcius and send to serial
  Serial.print(" C  - ");   
  Serial.print(temp.fah()); //It gets the temperature in fahrenheit and send to serial
  Serial.print(" F  - ");
  Serial.print(temp.kel()); //It gets the temperature in kelvin and send to serial
  Serial.println(" K");     // Send a text to serial and give a new line 
  Serial.println(" ");      // Blank line

  delay(1000);
}


