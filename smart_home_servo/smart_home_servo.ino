#define BLYNK_PRINT Serial  
//Definisi Serial pada Blink 

//Setting Library 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include <Servo.h> // ini library untuk servo

//Definisi variabel token, SSID, password 
char auth[] = "***************************"; 
char ssid[] = " namahostpotmu "; 
char pass[] = " passwordhostpotmu "; 

//Definisi fungsi servo menjadi gerak_servo 
Servo gerak_servo; 

//Fungsi Blynk untuk mengatur nilai servo dengan pin virtual V1 
BLYNK_WRITE(V1){ 
  gerak_servo.write(param.asInt()); 
}

//Settingan awal default 

void setup()
{ 
 Serial.begin(9600); //memulai serial monitor dengan baudrate 9600 

  
 gerak_servo.attach(2); //setting pin gpio 2 ke servo, D4 = 2 

  
 Blynk.begin(auth, ssid, pass);//setting blynk 


} //Good
=======
} 
void loop()
{ 
  Blynk.run();//memulai blynk 
  
}

