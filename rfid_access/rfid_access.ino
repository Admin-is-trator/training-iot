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
