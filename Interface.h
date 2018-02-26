// Traitement des commandes de l'interfarce Android

void _Mise_Heure()
{
  for ( int i=3; i>-1; i--)
  {
    char commande=_BluetoothReception();
    switch (commande)
    {
      case '0':
        _Ecran(i,0);
        break;
      case '1':
        _Ecran(i,1);
        break;
      case '2':
        _Ecran(i,2);
        break;
      case '3':
        _Ecran(i,3);
        break;
      case '4':
        _Ecran(i,4);
        break;
      case '5':
        _Ecran(i,5);
        break;
      case '6':
        _Ecran(i,6);
        break;
      case '7':
        _Ecran(i,7);
        break;
      case '8':
        _Ecran(i,8);
        break;
      case '9':
        _Ecran(i,9);
        break;
    }
  }
}

void _Eclairage()
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
        lc.setIntensity(0,2);
        lc.setIntensity(1,2);
        lc.setIntensity(2,2);
        lc.setIntensity(3,2);
        break;
      case '2':
        lc.setIntensity(0,4);
        lc.setIntensity(1,4);
        lc.setIntensity(2,4);
        lc.setIntensity(3,4);
        break;
      case '3':
        lc.setIntensity(0,6);
        lc.setIntensity(1,6);
        lc.setIntensity(2,6);
        lc.setIntensity(3,6);
        break;
      case '4':
        lc.setIntensity(0,8);
        lc.setIntensity(1,8);
        lc.setIntensity(2,8);
        lc.setIntensity(3,8);
        break;
      case '5':
        lc.setIntensity(0,10);
        lc.setIntensity(1,10);
        lc.setIntensity(2,10);
        lc.setIntensity(3,10);
        break;
      case '6':
        lc.setIntensity(0,12);
        lc.setIntensity(1,12);
        lc.setIntensity(2,12);
        lc.setIntensity(3,12);
        break;
      case '7':
        lc.setIntensity(0,14);
        lc.setIntensity(1,14);
        lc.setIntensity(2,14);
        lc.setIntensity(3,14);
        break;
    }
}
void _LCD_HEURE()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  _LIRE_HEURE(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  bcdToDec(minute);
  switch (minute/10)
  {
      case 0:
        _Ecran(1,0);
        break;
      case 1:
        _Ecran(1,1);
        break;
      case 2:
        _Ecran(1,2);
        break;
      case 3:
        _Ecran(1,3);
        break;
      case 4:
        _Ecran(1,4);
        break;
      case 5:
        _Ecran(1,5);
        break;
      case 6:
        _Ecran(1,6);
        break;
      case 7:
        _Ecran(1,7);
        break;
      case 8:
        _Ecran(1,8);
        break;
      case 9:
        _Ecran(1,9);
        break;
    }
  switch (minute%10)
  {
      case 0:
        _Ecran(0,0);
        break;
      case 1:
        _Ecran(0,1);
        break;
      case 2:
        _Ecran(0,2);
        break;
      case 3:
        _Ecran(0,3);
        break;
      case 4:
        _Ecran(0,4);
        break;
      case 5:
        _Ecran(0,5);
        break;
      case 6:
        _Ecran(0,6);
        break;
      case 7:
        _Ecran(0,7);
        break;
      case 8:
        _Ecran(0,8);
        break;
      case 9:
        _Ecran(0,9);
        break;
    }
  bcdToDec(hour);
  switch (hour/10)
  {
      case 0:
        _Ecran(3,0);
        break;
      case 1:
        _Ecran(3,1);
        break;
      case 2:
        _Ecran(3,2);
        break;
      case 3:
        _Ecran(3,3);
        break;
      case 4:
        _Ecran(3,4);
        break;
      case 5:
        _Ecran(3,5);
        break;
      case 6:
        _Ecran(3,6);
        break;
      case 7:
        _Ecran(3,7);
        break;
      case 8:
        _Ecran(3,8);
        break;
      case 9:
        _Ecran(3,9);
        break;
    }
  switch (hour%10)
  {
      case 0:
        _Ecran(2,0);
        break;
      case 1:
        _Ecran(2,1);
        break;
      case 2:
        _Ecran(2,2);
        break;
      case 3:
        _Ecran(2,3);
        break;
      case 4:
        _Ecran(2,4);
        break;
      case 5:
        _Ecran(2,5);
        break;
      case 6:
        _Ecran(2,6);
        break;
      case 7:
        _Ecran(2,7);
        break;
      case 8:
        _Ecran(2,8);
        break;
      case 9:
        _Ecran(2,9);
        break;
    }
}
