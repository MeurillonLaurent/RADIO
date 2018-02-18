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

#define DS3231_I2C_ADDRESS 0x68
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte
dayOfMonth, byte month, byte year)
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
void readDS3231time(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
void displayTime()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  // send it to the serial monitor
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  Serial.print(" Day of week: ");
  switch(dayOfWeek){
  case 1:
    Serial.println("Sunday");
    break;
  case 2:
    Serial.println("Monday");
    break;
  case 3:
    Serial.println("Tuesday");
    break;
  case 4:
    Serial.println("Wednesday");
    break;
  case 5:
    Serial.println("Thursday");
    break;
  case 6:
    Serial.println("Friday");
    break;
  case 7:
    Serial.println("Saturday");
    break;
  }
}
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
