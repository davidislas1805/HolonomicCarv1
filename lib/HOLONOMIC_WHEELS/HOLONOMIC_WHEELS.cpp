#include "HOLONOMIC_WHEELS.h"


HOLONOMIC_WHEELS::HOLONOMIC_WHEELS()
{
    
}

HOLONOMIC_WHEELS::~HOLONOMIC_WHEELS()
{
    
}

void HOLONOMIC_WHEELS::setup(byte front_right_pins[2], byte rear_right_pins[2], byte rear_left_pins[2], byte front_left_pins[2])
{
    right_front_motor.setup(front_right_pins, _right_front_channels, HIGH);
    right_rear_motor.setup(rear_right_pins, _right_rear_channels, HIGH);
    left_rear_motor.setup(rear_left_pins, _left_rear_channels, HIGH);
    left_front_motor.setup(front_left_pins, _left_front_channels, HIGH);
    
    right_front_motor.move(0);
    right_rear_motor.move(0);
    left_rear_motor.move(0);
    left_front_motor.move(0);
}

void HOLONOMIC_WHEELS::forward(int pwm)
{
    right_front_motor.move(pwm);
    right_rear_motor.move(pwm);
    left_rear_motor.move(pwm);
    left_front_motor.move(pwm);
}

void HOLONOMIC_WHEELS::forwardRight(int pwm)
{
    right_front_motor.move(0);
    right_rear_motor.move(pwm);
    left_rear_motor.move(0);
    left_front_motor.move(pwm);
}

void HOLONOMIC_WHEELS::forwardLeft(int pwm)
{
    right_front_motor.move(pwm);
    right_rear_motor.move(0);
    left_rear_motor.move(pwm);
    left_front_motor.move(0);
}

void HOLONOMIC_WHEELS::backward(int pwm)
{
    right_front_motor.move(-pwm);
    right_rear_motor.move(-pwm);
    left_rear_motor.move(-pwm);
    left_front_motor.move(-pwm);
}

void HOLONOMIC_WHEELS::backwardRight(int pwm)
{
    right_front_motor.move(-pwm);
    right_rear_motor.move(0);
    left_rear_motor.move(pwm);
    left_front_motor.move(0);
}

void HOLONOMIC_WHEELS::backwardLeft(int pwm)
{
    right_front_motor.move(0);
    right_rear_motor.move(-pwm);
    left_rear_motor.move(0);
    left_front_motor.move(-pwm);
}

void HOLONOMIC_WHEELS::clockwise(int pwm)
{
    right_front_motor.move(-pwm);
    right_rear_motor.move(-pwm);
    left_rear_motor.move(pwm);
    left_front_motor.move(pwm);
}

void HOLONOMIC_WHEELS::counterClockwise(int pwm)
{
    right_front_motor.move(pwm);
    right_rear_motor.move(pwm);
    left_rear_motor.move(-pwm);
    left_front_motor.move(-pwm);
}

void HOLONOMIC_WHEELS::moveRight(int pwm)
{
    right_front_motor.move(-pwm);
    right_rear_motor.move(pwm);
    left_rear_motor.move(-pwm);
    left_front_motor.move(pwm);
}

void HOLONOMIC_WHEELS::moveLeft(int pwm)
{
    right_front_motor.move(pwm);
    right_rear_motor.move(-pwm);
    left_rear_motor.move(pwm);
    left_front_motor.move(-pwm);
}

void HOLONOMIC_WHEELS::stopMoving()
{
    right_front_motor.move(0);
    right_rear_motor.move(0);
    left_rear_motor.move(0);
    left_front_motor.move(0);
}
