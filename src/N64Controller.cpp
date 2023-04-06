#include "N64Controller.h"
#include <Arduino.h>

N64Controller::N64Controller(HardwareSerial *serialPort) {
  interface = new N64Interface_ESP32(serialPort);
}

void N64Controller::begin() {
    interface->init();
}

void N64Controller::print_N64_status()
{
    // bits: A, B, Z, Start, Dup, Ddown, Dleft, Dright
    // bits: 0, 0, L, R, Cup, Cdown, Cleft, Cright
    Serial.println();
    Serial.print("Start: ");
    Serial.println(Start());

    Serial.print("Z:     ");
    Serial.println(Z());

    Serial.print("B:     ");
    Serial.println(B());

    Serial.print("A:     ");
    Serial.println(A());

    Serial.print("L:     ");
    Serial.println(L());
    Serial.print("R:     ");
    Serial.println(R());

    Serial.print("Cup:   ");
    Serial.println(C_up());
    Serial.print("Cdown: ");
    Serial.println(C_down());
    Serial.print("Cright:");
    Serial.println(C_right());
    Serial.print("Cleft: ");
    Serial.println(C_left());
    
    Serial.print("Dup:   ");
    Serial.println(D_up());
    Serial.print("Ddown: ");
    Serial.println(D_down());
    Serial.print("Dright:");
    Serial.println(D_right());
    Serial.print("Dleft: ");
    Serial.println(D_left());

    Serial.print("Stick X:");
    Serial.println(axis_x(), DEC);
    Serial.print("Stick Y:");
    Serial.println(axis_y(), DEC);
}

void N64Controller::update() {
  unsigned char command[] = {0x01};
  noInterrupts();
  interface->send(command, 1);
  interface->get();
  interrupts();
}
