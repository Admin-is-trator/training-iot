
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 5
#define SS_PIN 4

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  while(!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  ShowReaderDetails();
  Serial.println(F("Scan PICC to see UID, type and data blocks.."));

#define BLYNK_PRINT Serial


#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <MFRC522.h> // import file MFRC522 yang sudah kita install

char auth[] = "***************************"; 
char ssid[] = " namahostpotmu "; 
char pass[] = " passwordhostpotmu "; 

#define SDA_PIN D2 // mendefinisikan SDA pin ke D2
#define RST_PIN D1 // mendefinisikan RST pin ke D1

int virtual_State = 0; 

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

}

void ShowReaderDetails(){
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if(v == 0x91){
    Serial.print(F(" = v1.0"));
  }
  else if(v == 0x92){
    Serial.print(F(" = v2.0"));
  }
  else{
    Serial.print(F(" (unknown)"));
  }
  Serial.println("");
  if((v == 0x00) || (v == 0xFF)){
    Serial.println(F("Warning: Communication failure, is the MFRC522 properly connected?"));
  }

MFRC522 mfrc522(SDA_PIN, RST_PIN); // setting mfrc dengan SDA dan RST

WidgetLCD lcd(V1); // setting pin virtual LCD ke V1 di aplikasi blynk

void setup() 
{
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  Blynk.begin(auth, ssid, pass);
  mfrc522.PCD_Init(); // Inisiasi MFRC522 card
  Serial.println("Approximate your card to the reader..."); // pesan untuk mentap kartu
  Serial.println();

}
       
void loop()      
{
  Blynk.run();
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  // menampilkan UID di serial Monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();  // UID dijadikan Huruf besar semua
    
  if(content.substring(1) == "57 67 8B 7B") // masukkan ID kartu disini
          {
            lcd.clear();
            lcd.print(0, 0, "UID for Card is");    // Menampilkan UID di LCD blynk
            lcd.print(0, 1, content);
            delay(10000);      
          } 
                          
          else
          {                  
            lcd.clear();
            lcd.print(0, 0, "Invalid card");      // Menampilkan pesan ditolak di LCD blynk
            lcd.print(0, 1, "Access Denied");
          }                           

}
