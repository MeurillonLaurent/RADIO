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
