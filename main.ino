/* bibliothèque qui crée d'autre port serie */
#include <SoftwareSerial.h>

/* Fichier externe de gestion des matrices leds */
#include "LedControl.h"

/* Fichier externe de gestion des matrices leds */
#include "Matrice.h"

/* Fichier externe de gestion du Bluetooth */
#include "Bluetooth.h"

/* Fichier externe de gestion de l'horloge */
#include <Wire.h>
#include "Rtc.h"

/* Fichier externe de gestion des commandes  
   Application Android
*/
#include "Interface.h"

void setup()
{
  Wire.begin();
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  // setDS3231time(30,42,21,4,26,11,14);
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
    _LCD_HEURE();
    lc.setColumn(1,0,B00100100);
    delay(250);
    char commande=_BluetoothReception();
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
    lc.setColumn(1,0,B00000000);
    delay(250);
}
