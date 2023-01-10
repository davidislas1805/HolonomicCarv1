#ifndef __PID_H__
#define __PID_H__
#include "Arduino.h"

class PID
{
    public:
        PID();
        ~PID();
        int control(float feedback, float reference, float time_delta);
        void setup(float kp, float ki, float kd);
        void setReference(float reference);

    private:
       float _kp = 0, _ki = 0, _kd = 0;
       float _reference, _feedback, _error,_error_integral, _error_previous;
       int pwm_controlled; 
};

#endif // __PID_H__