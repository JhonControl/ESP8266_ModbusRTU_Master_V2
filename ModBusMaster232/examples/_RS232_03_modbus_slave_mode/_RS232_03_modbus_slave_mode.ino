/*   
 *  This sketch shows the use of the Modbus communication protocol over
 *  RS-232 standard, and the use of the main functions of the library.
 *. Modbus allows for communication between many devices connected
 *  to the same network. There are many variants of Modbus protocols,
 *  but Arduino implements the RTU format. Modbus RTU is the most
 *  common implementation available for Modbus.
 *  
 *  This example shows how to configure the Arduino as a Modbus
 *  slave  device. 
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

// Include always this library when you are using Modbus functions
#include <ModbusSlave232.h>

// Create new mbs instance
ModbusSlave232 mbs;

// Slave registers
enum {        
  MB_0,   // Register 0
  MB_1,   // Register 1
  MB_2,   // Register 2
  MB_3,   // Register 3  
  MB_4,   // Register 4  
  MB_REGS // Dummy register. using 0 offset to keep size of array
};

int regs[MB_REGS];

void setup(){

  // Modbus slave configuration parameters
  // SlaveId 
  const unsigned char SLAVE = 1;
  // Baud rate   
  const long BAUD = 9600;            
  const unsigned PARITY = 'n';

  // Configure msb with config settings
  mbs.configure(SLAVE, BAUD, PARITY );

}

void loop()
{
  // Pass current register values to mbs
  mbs.update(regs, MB_REGS);

  // Read all the analog Inputs, and store the values in
  // the Modbus registers.   
  regs[MB_0] = analogRead(A0);  // Analog 0 value
  regs[MB_1] = analogRead(A1);  // Analog 1 value
  regs[MB_2] = analogRead(A3);  // Analog 2 value
  regs[MB_3] = analogRead(A3);  // Analog 3 value

  delay(1000);

}

