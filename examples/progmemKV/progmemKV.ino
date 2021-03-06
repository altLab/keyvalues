/*
 * Filename: progmemKV.ino
 * Description: Example for library keyvalues
 *
 * Version: 1.0.0
 * Author: Joao Alves <jpralves@gmail.com>
 * Required files: -
 * Required Libraries: keyvalues
 * Tested on: Arduino Nano, Arduino Uno, ESP8266
 *
 * History:
 * 1.0.0 - 2017-03-14 - Initial Version
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if (defined(__AVR__))
#include <avr/pgmspace.h>
#else
#include <pgmspace.h>
#endif

#include "kvstring.h"

KVString kvs;

void setup() {
  Serial.begin(9600);
  // Simple set value:
  kvs.put("key1","value1");
	// Pass a K=V:
  kvs.putKV("key2=value2");
	// Pass a bunch of KV from PROGMEM:
  kvs.putKVs(F("key3=value3\nkey4=value4\nkey5=value5"));
	// List all keys stored:
  listKVs();
}

void listKVs() {
  String k, v;
  uint16_t keycount = kvs.size();
  
  Serial.print(keycount);
  Serial.println(F(" K/V found."));
  for (uint16_t i = 0; i < keycount; i++) {
    if (kvs.get(i, k, v)) {
  		Serial.print(k);
  		Serial.print(" = ");
  		Serial.println(v);  
    }
  }
}

void loop() {}
