#ifndef __HOLONOMIC_WHEELS_H__
#define __HOLONOMIC_WHEELS_H__
#include "MOTOR_DIRECTION.h"
#include "Arduino.h"

class HOLONOMIC_WHEELS{
    public: 
        HOLONOMIC_WHEELS();
        ~HOLONOMIC_WHEELS();
        void setup(byte front_right_pins[2], byte rear_right_pins[2], byte rear_left_pins[2], byte front_left_pins[2]);
        void forward(int pwm);
        void forwardRight(int pwm);
        void forwardLeft(int pwm);
        void backward(int pwm);
        void backwardRight(int pwm);
        void backwardLeft(int pwm);
        void clockwise(int pwm);
        void counterClockwise(int pwm);
        void moveRight(int pwm);
        void moveLeft(int pwm);
        void stopMoving();

    private:
        MOTOR_DIRECTION right_front_motor;
        MOTOR_DIRECTION right_rear_motor;
        MOTOR_DIRECTION left_rear_motor;
        MOTOR_DIRECTION left_front_motor;
        byte _right_front_channels[2] = {0, 1};
        byte _right_rear_channels[2] = {2, 3};
        byte _left_rear_channels[2] = {4, 5};
        byte _left_front_channels[2] = {6, 7};
};
#endif // __HOLONOMIC_WHEELS_H__