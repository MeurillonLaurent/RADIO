#ifndef __Matrice_h_
#define __Matrice_h_
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
byte Matrice_heure[5][8]=
{
// symbole horloge 1 
  {
    B00111100,
    B01000010,
    B10001001,
    B10001001,
    B11111001,
    B10000001,
    B01000010,
    B00111100
  },
// symbole horloge 2 
  {
    B00111100,
    B01000010,
    B10101001,
    B10011001,
    B10001001,
    B10000001,
    B01000010,
    B00111100
  },
// symbole horloge 3 
  {
    B00111100,
    B01001010,
    B10001001,
    B10001001,
    B10001001,
    B10000001,
    B01000010,
    B00111100
  },
// lettre O
  {
    B00000000,
    B00011100,
    B00100010,
    B00100010,
    B00100010,
    B00100010,
    B00011100,
    B00000000
  },
// lettre K
  {
    B00000000,
    B00100010,
    B00100100,
    B00111000,
    B00100100,
    B00100010,
    B00100010,
    B00000000
  }
};
int i,Symb;
// Pin 13 Arduino ==> DataIn Max7219
// Pin 12 Arduino ==> CLK Max7219
// Pin 11 Arduino ==> LOAD/CS Max7219
LedControl lc=LedControl(13,12,11,4);

void _Ecran(int Matrice, int Num_Ecran, int Symb)
{
  for (int i=0; i<8; i++)
  {
    switch (Matrice)
    {
      case 0:
        lc.setRow(Num_Ecran,i,t[Symb][i]);
        break;
      case 1:
        lc.setRow(Num_Ecran,i,Matrice_heure[Symb][i]);
        break;
    }
  }
}
void _Efface(int Num_Ecran)
{
  for (int i=0; i<8; i++)
  {
    lc.setColumn(Num_Ecran,i,B00000000);
  }
}
#endif
