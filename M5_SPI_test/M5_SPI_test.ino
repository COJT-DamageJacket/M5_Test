#include <SPI.h>              // We use this library, so it must be called here.
#include <MCP23S17.h>         // Here is the new class to make using the MCP23S17 easy.
#include <M5Stack.h>

MCP chip0(0, 2);//CS_Pin=2
MCP chip1(0, 5);//CS_Pin=5

static int delay_time=100;

void setup() {
  M5.begin();

  chip0.begin();
  chip1.begin();
  for (int i = 1; i <= 16; i++) {
    chip0.pinMode(i, HIGH);
    chip1.pinMode(i, HIGH);
  }
}

void loop() {
  for (int i = 1; i <=16; i++) {
    chip0.digitalWrite(i, HIGH); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }
  for (int i = 1; i <=16; i++) {
    chip0.digitalWrite(i, LOW); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }
    for (int i = 1; i <=16; i++) {
    chip1.digitalWrite(i, HIGH); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }
  for (int i = 1; i <=16; i++) {
    chip1.digitalWrite(i, LOW); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    delay(delay_time);
  }

  M5.update();
}
