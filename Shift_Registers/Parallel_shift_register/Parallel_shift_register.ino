int latchpin=11;
int clockpin=9;
int datapin=12;
int dt=250;

byte led1s=0b10101010;
byte led2s=0b01010101;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(latchpin,OUTPUT);
   pinMode(datapin,OUTPUT);
   pinMode(clockpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(latchpin,LOW);
   shiftOut(datapin,clockpin,LSBFIRST,led1s);
   digitalWrite(latchpin,HIGH);
   delay(dt);
   digitalWrite(latchpin,LOW);
   shiftOut(datapin,clockpin,LSBFIRST,led2s);
   digitalWrite(latchpin,HIGH);
   delay(dt);
}
