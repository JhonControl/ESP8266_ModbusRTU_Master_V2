/*
 *  This sketch shows how to send data through RS-232 standard.
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

  // Configure the multiplexer select pin
  pinMode(5, OUTPUT);

  Serial.begin(9600);
  delay(100);

  // Hello message
  Serial.println("Hello this is RS-232 communication send example!");
  delay(100);

}

void loop() {
  // Using the SOCKET1
  digitalWrite(5, HIGH);

  // Reading the analog input 1
  int analog0 = analogRead(A0);
  // Temperature formula TMP36
  float temperature =  100.0 * (analog0 * 5.0) / 1023 - 50;


  // Send data through RS-232 line
  Serial.print("Temperature from TMP36 : ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000);
}

