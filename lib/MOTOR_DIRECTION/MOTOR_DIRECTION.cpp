#include "MOTOR_DIRECTION.h"

MOTOR_DIRECTION::MOTOR_DIRECTION()
{
    
}

MOTOR_DIRECTION::~MOTOR_DIRECTION()
{
    
}

void MOTOR_DIRECTION::setup(const byte pins[2], const byte channels[2], bool on_state, double frequency, uint8_t bit_resolution)
{
    gpio[0].setup(pins[0], channels[0], frequency, bit_resolution, on_state);
    gpio[1].setup(pins[1], channels[1], frequency, bit_resolution, on_state);
}

void MOTOR_DIRECTION::move(float pwm)
{
    if (pwm < 0){
        gpio[0].setDigitalLevel(0);
        gpio[1].setDigitalLevel(fabs(pwm));
    }
    else if (pwm > 0){
        gpio[0].setDigitalLevel(pwm);
        gpio[1].setDigitalLevel(0);
    }
    else{
        gpio[0].setDigitalLevel(0);
        gpio[1].setDigitalLevel(0);
    }
}
