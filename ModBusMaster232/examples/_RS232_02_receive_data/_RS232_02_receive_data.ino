/*   
 *  This sketch shows how to receive data through RS-232 standard.
 *  This standard defines the electrical characteristics of drivers
 *  and receivers for use in digital systems. It does not specify
 *  or recommend any communications protocol. For a complete
 *  communication protocol, please see the Modbus examples.
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


void setup() {

  // Note: For viewing data in the serial monitor, you should open
  // the Serial at the same speed
  Serial.begin(9600);
  delay(100);

  //Print hello message.
  Serial.println("Hello this is RS-232 communication receive data example.");
}



void loop() { 

  // If data in response buffer
  if (Serial.available())
  {
    while (Serial.available()) {
      // Read one byte from the buffer      
      // Print data received in the serial monitor    
      Serial.print(char(Serial.read()));
    }

    Serial.print("\n");
  }

  delay(100);

}


