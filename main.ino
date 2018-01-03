/* bibliothèque qui crée d'autre port serie */
#include <SoftwareSerial.h>

/* Fichier externe de gestion du Bluetooth */
#include "Bluetooth.h"
/* Port Tx = 9 Port Rx = 10*/
SoftwareSerial HC06(9,10);

void setup()
{
    // Ouvre la voie série avec l'ordinateur
    Serial.begin(9600);
    // Ouvre la voie série avec le module BT
    HC06.begin(9600);
    Serial.println("ENTER AT Commands:");
}

void loop()
{
   //int reception=Serial.read();
   if (HC06.available()) 
   {
       Serial.println(HC06.read());
   }
   if (Serial.available())
   {
       HC06.println(Serial.read());
   }
}
