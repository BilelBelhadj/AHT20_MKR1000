/*
  Titre      : aht20_MKR1000
  Auteur     : Bilel Belhadj
  Date       : 08/09/2022
  Description: essayer le capteur aht20 pour la premiere fois a l'aide de AHTx0 Library
  Sources    : https://learn.adafruit.com/adafruit-aht20?view=all&gclid=Cj0KCQjwpeaYBhDXARIsAEzItbFtr8QpkVE7wLX3wJLSeQwXoFfKS1_2ZQa_fxPY0A8D85gWhwEDVcUaAv9uEALw_wcB
  Version    : 0.0.1
*/

//library necessaire
#include <Arduino.h>
#include <Adafruit_AHTX0.h>  
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"


//declaration des constantes
const int DEL = 10000;

//declaration des variables
Adafruit_AHTX0 aht;
sensors_event_t humidity, temp;



void setup() {

  Serial.begin(9600);
  /*
  //branchement au réseau WIFI
  wifiConnect();        
  MQTTConnect(); 
  */
  //verifier l'existance du AHT20
  if (aht.begin()) {
    Serial.println("Found AHT20");
  } else {
    Serial.println("Didn't find AHT20");
  }

}


void loop() {
  
  aht.getEvent(&humidity, &temp); //capturing data

  //printing results i, serial monitor
  Serial.print("Temperature: "); 
  Serial.print(temp.temperature); 
  Serial.println("C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity); 
  Serial.println("%");

  /*
  appendPayload("Temperature", temp.temperature);  //Ajout de la donnée température au message MQTT
  appendPayload("Humidity", humidity.relative_humidity);  //Ajout de la donnée humidity au message MQTT
  sendPayload();                                 //Envoie du message via le protocole MQTT    
  */

  delay(DEL);
}