#ifndef N64Controller_h
#define N64Controller_h

#include <HardwareSerial.h>
#include "N64Interface.h"

#define A_IDX       0
#define B_IDX       1
#define Z_IDX       2
#define START_IDX   3
#define D_UP_IDX    4
#define D_DOWN_IDX  5
#define D_LEFT_IDX  6
#define D_RIGHT_IDX 7
#define L_IDX       10
#define R_IDX       11
#define C_UP_IDX    12
#define C_DOWN_IDX  13
#define C_LEFT_IDX  14
#define C_RIGHT_IDX 15
#define X_IDX       16
#define Y_IDX       24

class N64Controller {
public:
  N64Controller(HardwareSerial *serialPort);
  void begin();
  void update();
  inline bool D_up() { return (interface->raw_dump[D_UP_IDX]) > 0; };
  inline bool D_down() { return (interface->raw_dump[D_DOWN_IDX]) > 0; };
  inline bool D_left() { return (interface->raw_dump[D_LEFT_IDX]) > 0; };
  inline bool D_right() { return (interface->raw_dump[D_RIGHT_IDX]) > 0; };
  inline bool Start() { return (interface->raw_dump[START_IDX]) > 0; };
  inline bool A() { return (interface->raw_dump[A_IDX]) > 0; };
  inline bool B() { return (interface->raw_dump[B_IDX]) > 0; };
  inline bool Z() { return (interface->raw_dump[Z_IDX]) > 0; };
  inline bool L() { return (interface->raw_dump[L_IDX]) > 0; };
  inline bool R() { return (interface->raw_dump[R_IDX]) > 0; };
  inline bool C_up() { return (interface->raw_dump[C_UP_IDX]) > 0; };
  inline bool C_down() { return (interface->raw_dump[C_DOWN_IDX]) > 0; };
  inline bool C_left() { return (interface->raw_dump[C_LEFT_IDX]) > 0; };
  inline bool C_right() { return (interface->raw_dump[C_RIGHT_IDX]) > 0; };
  inline char axis_x() { return axis(X_IDX); };
  inline char axis_y() { return axis(Y_IDX); };
  
  void print_N64_status();
private:
  N64Interface * interface;
  HardwareSerial *serial;

  inline char axis(int index) {
    char value = 0;
    for (char i = 0; i < 8; i++) {
      value |= interface->raw_dump[index+i] ? (0x80 >> i) : 0;
    }
    return value;
  }
};

#endif
