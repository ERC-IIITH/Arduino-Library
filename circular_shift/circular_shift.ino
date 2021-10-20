int latchpin=11;
int clockpin=9;
int datapin=12;
int dt=250;
byte led1s=0b00000001;

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
   led1s=led1s/128+led1s*2;  //left shift//
   //led1s=led1s*128+led1s/2;  //right shift//
}
