
int latchpin=11;
int clockpin=9;
int datapin=12;
int dt=1000;
byte led1s=0b10000000;

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
   //led1s=led1s*2;  //LEFT SHIFT//
   //led1s=led1s/2;  //RIGHT SHIFT//
   
}
