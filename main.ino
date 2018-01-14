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
    if (commande=='H')
    {
      _Mise_Heure();
    }
    if (commande=='I')
    {
      char commande=_BluetoothReception();
    switch (commande)
    {
      case '0':
        lc.setIntensity(0,0);
        lc.setIntensity(1,0);
        lc.setIntensity(2,0);
        lc.setIntensity(3,0);
        break;
      case '1':
        lc.setIntensity(0,1);
        lc.setIntensity(1,1);
        lc.setIntensity(2,1);
        lc.setIntensity(3,1);
        break;
      case '2':
        lc.setIntensity(0,2);
        lc.setIntensity(1,2);
        lc.setIntensity(2,2);
        lc.setIntensity(3,2);
        break;
      case '3':
        lc.setIntensity(0,3);
        lc.setIntensity(1,3);
        lc.setIntensity(2,3);
        lc.setIntensity(3,3);
        break;
      case '4':
        lc.setIntensity(0,4);
        lc.setIntensity(1,4);
        lc.setIntensity(2,4);
        lc.setIntensity(3,4);
        break;
      case '5':
        lc.setIntensity(0,5);
        lc.setIntensity(1,5);
        lc.setIntensity(2,5);
        lc.setIntensity(3,5);
        break;
      case '6':
        lc.setIntensity(0,6);
        lc.setIntensity(1,6);
        lc.setIntensity(2,6);
        lc.setIntensity(3,6);
        break;
      case '7':
        lc.setIntensity(0,7);
        lc.setIntensity(1,7);
        lc.setIntensity(2,7);
        lc.setIntensity(3,7);
        break;
      case '8':
        lc.setIntensity(0,8);
        lc.setIntensity(1,8);
        lc.setIntensity(2,8);
        lc.setIntensity(3,8);
        break;
      case '9':
        lc.setIntensity(0,9);
        lc.setIntensity(1,9);
        lc.setIntensity(2,9);
        lc.setIntensity(3,9);
        break;
    }
    }
}
