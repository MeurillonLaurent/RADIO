/* bibliothèque qui crée d'autre port serie */
#include <SoftwareSerial.h>

/* Fichier externe de gestion des matrices leds */
#include "LedControl.h"

/* Fichier externe de gestion des matrices leds */
#include "Matrice.h"

/* Fichier externe de gestion du Bluetooth */
#include "Bluetooth.h"

/* Fichier externe de gestion des commandes  
   Application Android
*/
#include "Interface.h"


void setup()
{
// Configuration des 4 écrans matrices
    lc.shutdown(0,false);
    lc.setIntensity(0,6);
    lc.clearDisplay(0);

    lc.shutdown(1,false);
    lc.setIntensity(1,6);
    lc.clearDisplay(1);

    lc.shutdown(2,false);
    lc.setIntensity(2,6);
    lc.clearDisplay(2);

    lc.shutdown(3,false);
    lc.setIntensity(3,6);
    lc.clearDisplay(3);

    // Ouvre la voie série avec l'ordinateur
    Serial.begin(9600);
    // Ouvre la voie série avec le module BT
    HC06.begin(9600);
    Serial.println("ENTER AT Commands:");
    _Ecran(0,2);
    _Ecran(1,3);
    _Ecran(2,0);
    _Ecran(3,1);
}

void loop()
{
    char commande=_BluetoothReception();
    delay(200);
    // réglage de l'heure
    if (commande=='H')
    {
      _Mise_Heure();
    }
    // réglage de l'éclairage
    if (commande=='I')
    {
      _Eclairage();
    }
}
