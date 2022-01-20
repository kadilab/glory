#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" //Our HTML webpage contents with javascripts

const int pins[4] = {16,5,4,0};
const int relais1 = 16 ,relais2 = 5,relais3 = 4,relais4 = 0;
const int capteur_feux = 14;


IPAddress local_IP(192,168,43,22);
IPAddress gateway(192,168,43,9);
IPAddress subnet(255,255,255,0);


ESP8266WebServer server(80); //Server on port 80

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void lampe1() {
 digitalWrite(relais1,LOW);
}
void lampe1off() {
 digitalWrite(relais1,HIGH);
}

void lampe2() {
 digitalWrite(relais2,LOW);
}
void lampe2off() {
 digitalWrite(relais2,HIGH);
}
void lampe3() {
 digitalWrite(relais3,LOW);
}
void lampe3off() {
 digitalWrite(relais3,HIGH);
}
void lampe4() {
 digitalWrite(relais4,LOW);
}
void lampe4off() {
 digitalWrite(relais4,HIGH);
}




void setup() { 
  
  Serial.begin(115200);  
  for(int i = 0; i<4;i++)
  {
      pinMode(pins[i],OUTPUT);  
      digitalWrite(pins[i],HIGH);
  }
  pinMode(capteur_feux, INPUT);
  

  WiFi.softAPConfig(local_IP, gateway, subnet);
  boolean result = WiFi.softAP("mtp-01", "mtp01234");
  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", handleRoot);//affichage de la page principale
  
  server.on("/lampe1", lampe1); //envoi des donnnees du capteur
  server.on("/lampe1off", lampe1off); //envoi des donnnees du capteur
  
  server.on("/lampe2", lampe2); //envoi des donnnees du capteur
  server.on("/lampe2off", lampe2off); //envoi des donnnees du 

  server.on("/lampe3", lampe3); //envoi des donnnees du capteur
  server.on("/lampe3off", lampe3off); //envoi des donnnees du capteur

  server.on("/prise1", lampe4); //envoi des donnnees du capteur
  server.on("/prise1off", lampe4off); //envoi des donnnees du capteur
  
  server.begin();                  //Start server
  Serial.println("HTTP server started");

  delay(5000);
  
   
}
void loop() {
   Serial.print("Feux : ");
   Serial.println(digitalRead(capteur_feux));
   server.handleClient();  //Handle client requests
}
