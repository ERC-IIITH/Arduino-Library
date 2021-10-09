// Initially the motor is off
int state = 0;

void setup()
{
  // Configuring pin modes
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, INPUT);
}

void loop()
{
  // Push button toggling the state
  int toggle;
  toggle = digitalRead(3);

  if (toggle == LOW)
  {
    state++;
    delay(500);
  }

  if (state == 0)
  {
    // Off
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  else if (state == 1)
  {
    // Clockwise
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  else if (state == 2)
  {
    // Anti-clockwise
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }
  else
  {
    state = 1;
    delay(500);
  }
}