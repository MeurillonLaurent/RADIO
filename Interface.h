#ifndef __Interface_h_
#define __Interface_h_
// Traitement des commandes de l'interfarce Android

void _Mise_Heure()
{
  // animation avant réglage
  _Ecran(1,3,0);
  _Efface(2);
  _Ecran(1,1,3);
  _Ecran(1,0,4);
  delay(1000);
  _Ecran(1,3,1);
  delay(1000);
  _Ecran(1,3,2);
  delay(1000);
  // animation avant réglage
  for ( int i=3; i>-1; i--)
  {
    char commande=_BluetoothReception();
    switch (commande)
    {
      case '0':
        _Ecran(0,i,0);
        break;
      case '1':
        _Ecran(0,i,1);
        break;
      case '2':
        _Ecran(0,i,2);
        break;
      case '3':
        _Ecran(0,i,3);
        break;
      case '4':
        _Ecran(0,i,4);
        break;
      case '5':
        _Ecran(0,i,5);
        break;
      case '6':
        _Ecran(0,i,6);
        break;
      case '7':
        _Ecran(0,i,7);
        break;
      case '8':
        _Ecran(0,i,8);
        break;
      case '9':
        _Ecran(0,i,9);
        break;
    }
  }
}

void _Eclairage()
{
    char commande=_BluetoothReception();
    switch (commande)
    {
      case '1':
        lc.setIntensity(0,0);
        lc.setIntensity(1,0);
        lc.setIntensity(2,0);
        lc.setIntensity(3,0);
        _Ecran(2,2,2);
        _Efface(1);
        _Efface(0);
        break;
      case '2':
        lc.setIntensity(0,2);
        lc.setIntensity(1,2);
        lc.setIntensity(2,2);
        lc.setIntensity(3,2);
        _Ecran(2,2,3);
        _Efface(1);
        _Efface(0);
        break;
      case '3':
        lc.setIntensity(0,4);
        lc.setIntensity(1,4);
        lc.setIntensity(2,4);
        lc.setIntensity(3,4);
        _Ecran(2,2,4);
        _Efface(1);
        _Efface(0);
        break;
      case '4':
        lc.setIntensity(0,6);
        lc.setIntensity(1,6);
        lc.setIntensity(2,6);
        lc.setIntensity(3,6);
        _Ecran(2,2,4);
        _Ecran(2,1,5);
        _Efface(0);
        break;
      case '5':
        lc.setIntensity(0,8);
        lc.setIntensity(1,8);
        lc.setIntensity(2,8);
        lc.setIntensity(3,8);
        _Ecran(2,2,4);
        _Ecran(2,1,6);
        _Efface(0);
        break;
      case '6':
        lc.setIntensity(0,10);
        lc.setIntensity(1,10);
        lc.setIntensity(2,10);
        lc.setIntensity(3,10);
        _Ecran(2,2,4);
        _Ecran(2,1,7);
        _Ecran(2,0,8);
        break;
      case '7':
        lc.setIntensity(0,12);
        lc.setIntensity(1,12);
        lc.setIntensity(2,12);
        lc.setIntensity(3,12);
        _Ecran(2,2,4);
        _Ecran(2,1,7);
        _Ecran(2,0,9);
        break;
      case '8':
        lc.setIntensity(0,14);
        lc.setIntensity(1,14);
        lc.setIntensity(2,14);
        lc.setIntensity(3,14);
        _Ecran(2,2,4);
        _Ecran(2,1,7);
        _Ecran(2,0,10);
        break;
    }
  _Ecran(2,3,0);
  delay(250);
  _Ecran(2,3,1);
  delay(250);
  _Ecran(2,3,0);
  delay(250);
  _Ecran(2,3,1);
  delay(250);
}
void _LCD_HEURE()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  _LIRE_HEURE(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  // converti les minutes en décimal
  bcdToDec(minute);
    // Unité des minutes chiffre à droite
    _Ecran(0,0,minute%10);
    // Dizaine de minute chiffre à gauche
    _Ecran(0,1,minute/10); 
  // converti les heures en décimal
  bcdToDec(hour);
    // Unité des minutes chiffre à droite
    _Ecran(0,2,hour%10);
    // Dizaine d'heure chiffre à gauche
    _Ecran(0,3,hour/10);
}
#endif
