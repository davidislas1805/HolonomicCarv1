#ifndef __MOTOR_DIRECTION_H__
#define __MOTOR_DIRECTION_H__

#include "PWM_ESP32.h"
#include <Arduino.h>


class MOTOR_DIRECTION{
    public:
        MOTOR_DIRECTION();
        ~MOTOR_DIRECTION();
        void setup(const byte pins[2], const byte channels[2], bool on_state, double frequency = 25000, uint8_t bit_resolution = 8);
        void move(float pwm);
    
    private:
        PWM gpio[2];
};

#endif // __MOTOR_DIRECTION_H__