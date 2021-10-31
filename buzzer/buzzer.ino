const int DOOR_SENSOR_PIN = 13; // Arduino pin connected to door sensor's pin
const int BUZZER_PIN      = 3;  // Arduino pin connected to Buzzer's pin

int doorState;

void setup() {
  Serial.begin(9600);                     // initialize serial
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(BUZZER_PIN, OUTPUT);            // set arduino pin to output mode
}

void loop() {
  doorState = digitalRead(DOOR_SENSOR_PIN); // read state

  if (doorState == HIGH) {
    Serial.println("The door is open");;
    digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
  } else {
    Serial.println("The door is closed");
    digitalWrite(BUZZER_PIN, LOW);  // turn off Piezo Buzzer
  }
}
