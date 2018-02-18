#ifndef __Bluetooth_h_
#define __Bluetooth_h_
// configuration du module Bluetooth

/* Port Tx = 9 Port Rx = 10*/
SoftwareSerial HC06(9,10);

char _BluetoothReception ()
{
   char reception;
   if (HC06.available()) 
   {
       reception=HC06.read();
       Serial.println(reception);
   }
   if (Serial.available())
   {
       reception=Serial.read();
       HC06.println(reception);
   }
return reception;
}
#endif
