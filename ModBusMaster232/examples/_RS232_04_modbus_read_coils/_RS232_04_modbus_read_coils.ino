/*
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
 */


#include <ModbusMaster232.h>

// Instantiate ModbusMaster object as slave ID 1
ModbusMaster232 node(1);

// Define one address for reading
#define address 1
// Define the number of bits to read
#define bitQty 1

void setup()
{
  // Initialize Modbus communication baud rate
  node.begin(19200);

  // Print hello message
 /// Serial.println("Modbus communication over RS-232");
  delay(100);
}


void loop()
{
  // This variable will store the result of the communication
  // result = 0 : no errors
  // result = 1 : error occurred
  int result =  node.readHoldingRegisters(address, bitQty);

    int dato = node.getResponseBuffer(0);
 ///Serial.print(dato);
/*
  if (result != 0) {
    // If no response from the slave, print an error message
    Serial.println("Communication error");
    delay(1000);
  }
  else {

    // If all ok
    Serial.print("Read value : ");

    // Print the read data from the slave


   
    delay(1000);
  }
*/
 // Serial.print("\n");
  delay(1000);

  // Clear the response buffer
  node.clearResponseBuffer();

}






