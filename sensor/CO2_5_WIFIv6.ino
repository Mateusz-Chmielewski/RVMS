#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>
#include "MHZ19.h"                                        
#define PIN D4
#define NUMPIXELS 16
MHZ19 myMHZ19;

bool zmien=0;
unsigned long getDataTimer = 0;
int CO2=0; 
int8_t Temp;
IPAddress staticIP(192, 168, 1, 14); //ESP static ip
IPAddress gateway(192, 168, 1, 1);   //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);  //Subnet mask
IPAddress dns(8, 8, 8, 8);  //DNS
const char* deviceName = "CO2_5";

const char* ssid = "Czujniki";
const char* password = "zaq1@WSX";

ESP8266WebServer server(80);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void handleRoot() {
   CO2 = myMHZ19.getCO2();                             // Request CO2 (as ppm)
        Temp = myMHZ19.getTemperature();  
 String przed = String("<!DOCTYPE html><html><body><center><br><h1>");
 String po = String(" PPM </h1></center> </body> </html>");
 server.send(200, "text/html", przed+String(CO2)+"  "+String(Temp)+po); 
 //server.send(200, "text/plain", "Hello, world");
}




HardwareSerial mySerial(0);
void setup(void) {
  pinMode(D3,OUTPUT);
  digitalWrite(D3,HIGH);
  pixels.begin();
  mySerial.begin(9600);
  myMHZ19.begin(mySerial);
  WiFi.begin(ssid, password);
  WiFi.hostname(deviceName);
  WiFi.config(staticIP, gateway, subnet, dns);
  WiFi.mode(WIFI_STA);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);

/*while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
  }
  */
  server.on("/", handleRoot);
  server.begin();
  
}

void loop(void) {
  server.handleClient();
if (millis() - getDataTimer >= 2000)
    {


        /* note: getCO2() default is command "CO2 Unlimited". This returns the correct CO2 reading even 
        if below background CO2 levels or above range (useful to validate sensor). You can use the 
        usual documented command with getCO2(false) */

        CO2 = myMHZ19.getCO2();                             // Request CO2 (as ppm)
        Temp = myMHZ19.getTemperature();                     // Request Temperature (as Celsius)
       // Serial.print("Temperature (C): ");                  
        //Serial.println(Temp);                               
        getDataTimer = millis();
        zmien=1;
    }
if(zmien==1)
{
  for(int i=0;i<NUMPIXELS;i++){
    if(CO2<=1000){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(102,204,1)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    if(CO2>1000){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(255,0,0)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }

    
  }
  zmien=0;
}

  

}
