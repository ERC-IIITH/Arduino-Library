int BUTTON = 2; // Pin connected to one of the push button's terminal. 
//Connect the diagonally opposite terminal to ground with a resistor in between.
int LED = 3; // Pin to which LED's longer terminal is connected. 
//Shorter terminal should be connected to Gnd
bool state = 0; // Variable to store the present state of the push button

void setup()
{
  pinMode(BUTTON, INPUT); // Declaring D2 as input pin
  pinMode(LED, OUTPUT); // Declaring D3 as output pin
}

void loop()
{
  state = digitalRead(BUTTON); // raed the button state and store it to the variable 'state'

  if (state == HIGH){
    digitalWrite(LED, HIGH);
  } 
  else{
    digitalWrite(LED, LOW);
  }
}
