#include "DHT.h"                        //include the DHT library
#include <LiquidCrystal.h>              //include the LiquidCrystal library
#define DHTPin 2                        //define DHT pin
LiquidCrystal lcd(1, 3, 4, 5, 6, 7);    //define LCD pins (RS, E, D4, D5, D6, D7)
DHT dht;

void setup() {
  dht.setup(DHTPin);  
  lcd.begin(16,2);                      //initializes the LCD and specifies the dimensions
}
void loop() {
  float temp = dht.getTemperature();
  float humi = dht.getHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(humi);
  lcd.print(" %");
  delay(2000);
}
