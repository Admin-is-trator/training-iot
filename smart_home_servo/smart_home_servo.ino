
#include <Servo.h> 
// membuat nama objek servo untuk pengontrolan servo 
Servo myservo;          
// variable untuk menyimpan posisi servo 
int pos = 0;            
void setup() 
{ 
 // objek servo diletakan pada pin 9 
 myservo.attach(16);  
 pinMode (2, OUTPUT);   
} 
void loop() 
{ 
 // start dari 0 derajar sampai 180 derajat 
 for(pos = 0; pos < 180; pos += 1)  
 {
  // pada posisi 1 derajat
  // memberitahu servo untuk pergi ke posisi  'pos'
  myservo.write(pos);
  // tunggu 15ms untuk pencapaian  posisi servo    
  delay(10);                  
 } 
 // start dari 180 derajat ke 0 derajat 
 for(pos = 180; pos>=1; pos-=1)  
 {
  // memberitahu servo untuk pergi ke posisi  'pos'                                
  myservo.write(pos);                 
  // tunggu 15ms untuk pencapaian  posisi servo    
  delay(10);                        
 }

 digitalWrite (2, HIGH);
 delay (2000);
 digitalWrite (2, LOW);
 delay (2000);
=======
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

