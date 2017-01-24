/*
 *  This sketch shows the use of the Modbus communication protocol over
 *  RS-232 standard, and the use of the main functions of the library.
 *. Modbus allows for communication between many devices connected
 *  to the same network. There are many variants of Modbus protocols,
 *  but Arduino implements the RTU format. Modbus RTU is the most
 *  common implementation available for Modbus.
 *
 *  This example shows the use of the function writeSingleRegiter().
 *  This function code is used to write a single holding register
 *  in a remote device.
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
 *  Design:           David Gascon
 *  Implementation:   Ahmad Saad
 */


//Include these libraries for using the RS-232 and Modbus functions
#include <ModbusMaster232.h>

// Instantiate ModbusMaster object as slave ID 1
ModbusMaster232 node(1);

//define one address for reading
#define address 1

//define the number of bytes to read
#define byteData 0

void setup()
{
  // Power on the USB for viewing data in the serial monitor.
  Serial.begin(9600);

  // Initialize Modbus communication baud rate
  node.begin(9600);

  //Print hello message
  Serial.println("Modbus communication over RS-232");
  delay(100);
}


void loop()
{
  // This variable will store the result of the communication
  // result = 0 : no errors
  // result = 1 : error occurred
  int result = node.writeSingleRegister(address, byteData);

  if (result != 0) {
    // If no response from the slave, print an error message
    Serial.println("Communication error");
    delay(100);
  }
  else {

    // If all ok
    Serial.print("Data writted successfully.");
    delay(100);
  }

  Serial.print("\n");
  delay(1000);

  // Clear the response buffer
  node.clearResponseBuffer();

}






