#ifndef _Encoder_h
#define _Encoder_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
// This code was improve thanks to the forum https://github.com/arduino/ArduinoCore-avr/issues/85
// and https://github.com/ghrasko

class Encoder
{
public:
  Encoder();
  ~Encoder();
  void setup(int ppr, const int pins[2]);
  float getRPM();
  float getPosition();
  void pollState(); // Class callback to be finally triggered by the interrupt

private:
  const int _DTS_US = 1000000;
  float _rpm, _prev_rpm, _position, _prev_pos, _current_pos, _time_delta;;
  volatile uint16_t _pulse_counter, out;
  unsigned long _prevTime = 0;
  float degrees;
  int _channelA, _channelB;
  volatile double _degrees_pp;
  volatile long _current_time, _prev_time;
  const int8_t QEM[16] = {0, -1, 1, 2, 1, 0, 2, -1, -1, 2, 0, 1, 2, 1, -1, 0};
  volatile uint8_t old = 0, new_value = 0; 
};

typedef struct callback
{                // callback table record structure
  void (*pcb)(); // pointer to pool callback routine
  Encoder *pobj; // place for object instance "this" pointer
} callback_t;
void px(callback_t *p);              // error catching wrapper for callbacks
void p0(), p1(), p2(), p3(), p4();   // callback routine pool
void (*registerCB(Encoder *pobj))(); // callback routine allocation routine

#endif