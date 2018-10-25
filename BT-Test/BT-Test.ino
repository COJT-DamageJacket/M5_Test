#include "BluetoothSerial.h"
#include <M5Stack.h>

BluetoothSerial SerialBT;

void setup() {
  M5.begin();
  
  SerialBT.begin("marimo-M5");
  SerialBT.println("Hello World");
}

void loop() {
  if (SerialBT.available()) {
    M5.Lcd.printf("%c",SerialBT.read());
    SerialBT.println("OK");
  }
  
  M5.update();
}
