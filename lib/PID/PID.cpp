#include "PID.h"

PID::PID()
{
}

PID::~PID()
{
}

int PID::control(float feedback, float reference, float time_delta = 0.0){    
    _reference = reference;
    _feedback = feedback;
    _error = _reference - _feedback;
    _error_integral = _error_integral + _error * time_delta;
    pwm_controlled = _kp * _error + _ki *_error_integral;
    // float error = _reference - input;
    // float _error_diff = error - _error_previous;
    // _error_integral += error;
    // _error_previous = error;
    // float pwm_controlled = _kp * error + _ki * _error_integral + _kd * _error_diff;
    if(pwm_controlled > 255){
        pwm_controlled = 255;
    }
    else if(pwm_controlled < -255){
        pwm_controlled = -255;
    }
    return pwm_controlled;
}

void PID::setup(float kp, float ki, float kd)
{
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

void PID::setReference(float reference)
{
    _reference = reference;
    
}