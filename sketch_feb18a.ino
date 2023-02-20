#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

ESP8266WebServer server(80);
const char* ssid = "Mira";//XPEH_BAM
const char* password = "ayhz3102";//31qrioN4


void setup() {

  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Non Connecting to WiFi..");
  }
  else
  {

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }



  server.on("/other", []() {

  server.send(200, "text/plain", "Humidity: 52%");
  

  });

  server.on("/", handleRootPath); 
  server.begin();
  Serial.println("Server listening");


}

void loop() {

  server.handleClient();

}

void handleRootPath() {

  server.send(200, "text/plain", "Temperature: 19 C");




}