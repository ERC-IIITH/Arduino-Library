#include "SPI.h"
#include <MFRC522.h>//https://github.com/miguelbalboa/rfid

//Constants
#define SS_PIN 21 # change according to board
#define RST_PIN 22

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
MFRC522::MIFARE_Key key;

void setup() {
    // Set software serial baud to 115200;
    Serial.begin(115200);

    SPI.begin();      // Starting SPI bus
    mfrc522.PCD_Init();
    delay(100);// Starting MFRC522
    Serial.println("Insert your card to the reader...");
    Serial.println();
}

void loop() {
    if ( ! mfrc522.PICC_IsNewCardPresent()) return;
    // Select one of the cards
    else if ( ! mfrc522.PICC_ReadCardSerial()) return;
    else {
        Serial.print("UID tag :");
        String content = "";
        byte letter;
        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
            Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
            Serial.print(mfrc522.uid.uidByte[i], HEX);
            content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
            content.concat(String(mfrc522.uid.uidByte[i], HEX));
        }
        Serial.println(content[0]);
   /* add your conditions for various tags here
    if (content[0]="")... else {}
    */
        delay(2000);// delay 
    }
} 
