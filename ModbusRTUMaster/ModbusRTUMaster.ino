/* https://www.cooking-hacks.com/documentation/tutorials/modbus-module-shield-tutorial-for-arduino-raspberry-pi-intel-galileo/
 *
 *  This sketch shows the use of the Modbus communication protocol over
 *  RS-232 standard, and the use of the main functions of the library.
 *. Modbus allows for communication between many devices connected
 *  to the same network. There are many variants of Modbus protocols,
 *  but Arduino implements the RTU format. Modbus RTU is the most
 *  common implementation available for Modbus.
 *
 *  This example shows the use of the function readCoils. This function
 *  requests the ON/OFF status of discrete coils from the slave device.
 *
 *  Copyright (C) 2014 Libelium Comunicaciones Distribuidas S.L.
 *  http://www.libelium.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Version:          0.1
 *  Implementation:   Ahmad Saad
 *  
 *  
 *  Modified by PDAControl
 *   Settings for libraries for ESP8266
 *  - Function  crc16 
 *  - Function  makeWord
 *  More info      : http://pdacontrolen.com
 *  Mas informacion: http://pdacontroles.com
 *  Channel  Youtube https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
 *  
 *   
 */


#include <ModbusMaster232.h>


// Instantiate ModbusMaster object as slave ID 1
ModbusMaster232 node(1);

//functions modbus
//node.readHoldingRegisters(,)
//node.writeSingleRegister(,)
// node.readInputRegisters(,);
// node.writeSingleCoil(,)
// node.readWriteMultipleRegisters(,,,)

const int analogInPin = A0; 
int led = 0 ;
int response = 0;
  
// Define one address for reading
#define address 1
// Define the number of bits to read
#define bitQty 1

void setup()
{
    pinMode(4, OUTPUT);
  // Initialize Modbus communication baud rate
  node.begin(19200);
  delay(100);
}


void loop()
{


 /// Write Digital Outputs - Holding Register[4]  /->  [5] ////////////
 response = node.readHoldingRegisters(4, 1); 
  /// get value - captura valor
 int led = node.getResponseBuffer(0);
 // GPIO 04 
 digitalWrite(4,led);
 // Clear the response buffer
 node.clearResponseBuffer();
    
  delay(100);
  
  // Send Random Value  - Holding Register[5]    /->  [6]  ////////////
  node.writeSingleRegister(5, random(1, 999 )); 
  
 delay(100);
  
  //Read Analog Input - Holding Register[6]     /->  [7] ////////////
  node.writeSingleRegister(6, analogRead(analogInPin) ); 


 delay(100);

 // Clear the response buffer
 node.clearResponseBuffer();
  

}






