#define BLYNK_PRINT Serial // digunakan untuk monitor blynk di serial monitor

#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk

char auth[] = "***************************"; 
char ssid[] = " Your Hotspot SSID "; 
char pass[] = " You Wifi Hotspot "; 

void setup() // fungsi utama, sekali dijalankan
{
  Serial.begin(9600); // untuk monitor di serial print
  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan paswordnya
  delay(1000);
  
}

void loop() // fungsi utama, berulang kali dijalankan
{
  Blynk.run(); // perintah untuk menjalankan blynk 
}
