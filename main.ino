/* bibliothèque qui crée d'autre port serie */
#include <SoftwareSerial.h>

/* Fichier externe de gestion du Bluetooth */
#include "Bluetooth.h"

#include "LedControl.h"

byte t[10][8]=
  {
  // 0 
    {
      B00000000,
      B00111100,
      B01100110,
      B01100110,
      B01100110,
      B01100110,
      B00111100,
      B00000000
    },
  // 1 
    {
      B00000000,
      B00011000,
      B00111000,
      B00011000,
      B00011000,
      B00011000,
      B00111100,
      B00000000
    },
  // 2 
    {
      B00000000,
      B00111000,
      B01101100,
      B00011000,
      B01110000,
      B01100000,
      B01111100,
      B00000000
    },
  // 3 
    {
      B00000000,
      B00111100,
      B01100110,
      B00001110,
      B00001110,
      B01100110,
      B00111100,
      B00000000
    },
  // 4 
    {
      B00000000,
      B00100100,
      B01100110,
      B01100110,
      B00111110,
      B00000110,
      B00000110,
      B00000000
    },
  // 5 
    {
      B00000000,
      B00111100,
      B01100000,
      B01111100,
      B00111110,
      B00000110,
      B00111100,
      B00000000
    },
  // 6 
    {
      B00000000,
      B00111100,
      B01100000,
      B01111100,
      B01111110,
      B01100110,
      B00111100,
      B00000000
    },
  // 7 
    {
      B00000000,
      B00111100,
      B01100110,
      B00000110,
      B00011110,
      B00000110,
      B00000110,
      B00000000
    },
  // 8 
    {
      B00000000,
      B00111100,
      B01100110,
      B01111110,
      B01111110,
      B01100110,
      B00111100,
      B00000000
    },
  // 9 
    {
      B00000000,
      B00111100,
      B01100110,
      B01111110,
      B00111110,
      B00000110,
      B00111100,
      B00000000
    }
  };
int i,Symb;
// Pin 13 Arduino ==> DataIn Max7219
// Pin 12 Arduino ==> CLK Max7219
// Pin 11 Arduino ==> LOAD/CS Max7219
LedControl lc=LedControl(13,12,11,4);

void _Matrice(int Num_MatLed, int Symb)
{
  for (int i=0; i<7; i++)
  {
    lc.setRow(Num_MatLed,i,t[Symb][i]);
  }
}

void setup()
{
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
    _Matrice(0,2);
    _Matrice(1,3);
    _Matrice(2,0);
    _Matrice(3,1);
}

void loop()
{
    char commande=_BluetoothReception();
    delay(200);
    if (commande=='H')
    {
      for ( int i=3; i>-1; i--)
      {
      char commande=_BluetoothReception();
      switch (commande)
      {
        case '0':
          _Matrice(i,1);
          break;
        case '1':
          _Matrice(i,1);
          break;
        case '2':
          _Matrice(i,2);
          break;
        case '3':
          _Matrice(i,3);
          break;
        case '4':
          _Matrice(i,4);
          break;
        case '5':
          _Matrice(i,5);
          break;
        case '6':
          _Matrice(i,6);
          break;
        case '7':
          _Matrice(i,7);
          break;
        case '8':
          _Matrice(i,8);
          break;
        case '9':
          _Matrice(i,9);
          break;
      }
      }
    }
}
