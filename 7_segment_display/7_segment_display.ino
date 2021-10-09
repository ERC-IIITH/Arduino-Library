
int disp[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}};
int pins[7] = {2, 3, 4, 5, 6, 7, 8};
int pin = 2, num, reset = 13;

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < 7; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
  digitalWrite(reset, HIGH);
  pinMode(reset, OUTPUT);
}

void loop()
{
  // Get input from serial port
  Serial.println("Display resets every 4 secs");
  Serial.print("Enter the number:");
  while (Serial.available() == 0)
    ;

  // Calculate value of input
  num = Serial.read() - '0';
  Serial.println(num);

  // Display the value on the 7 segment display
  for (int j = 0; j < 7; j++)
  {
    digitalWrite(pin, disp[num][j]);
    pin++;
  }
  // Reset after 4 seconds
  delay(4000);
  digitalWrite(reset, LOW);
}