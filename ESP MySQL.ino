/* SciFi Labs - follow us on Instagram (@scifi_labs) (@techxaperture)
 * Complete project details at scifilabs.blogspot.com
 * 
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "###########"; // replace # with your ssid  
const char* password = "############"; // replace # with your wifi password
//WiFiClient client;
char server[] = "############";   //eg: 192.168.0.222 (relpace # with your IP ADDRESS)


WiFiClient client;    
float ldr;

void setup()
{
 pinMode(A0,INPUT);
 Serial.begin(115200);
  delay(10);
 
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  //server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
 }
void loop()
{ 
  ldr= analogRead(A0); // READ LDR VALUE FROM PIN A0
   Sending_To_phpmyadmindatabase(); 
  delay(30000); // interval
 }

 void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server,80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("VALUE=");    
    Serial.println(ldr);
    client.print("GET /Test0/sensor.php?VALUE=");
    client.print(ldr);
    client.print(" ");      
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 192.168.1.3");
    client.println("Connection: close");
    client.println();
    
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
