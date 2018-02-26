#ifndef __Rtc_h_
#define __Rtc_h_

#define DS3231_I2C_ADDRESS 0x68

/** Fonction de conversion decimal -> BCD */
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
/** Fonction de conversion BCD -> decimal */
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}
/* 
Fonction récupérant l'heure et la date 
courante à partir du module RTC.
*/

void _LIRE_HEURE
 ( byte *second,
   byte *minute,
   byte *hour,
   byte *dayOfWeek,
   byte *dayOfMonth,
   byte *month,
   byte *year
 )
{
  /* Début de la transaction I2C */
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // Lecture mémoire à l'adresse 0x00
  Wire.endTransmission(); // Fin de la transaction I2C

  /* Lit 7 octets depuis la mémoire du module RTC */
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
void _ENREGISTRE_HEURE
 ( byte second, 
   byte minute, 
   byte hour, 
   byte dayOfWeek, 
   byte dayOfMonth, 
   byte month, 
   byte year
)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
#endif
