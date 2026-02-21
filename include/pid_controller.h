/*
 * Header file for the PIDController class.
 * Defines the structure for calculating motor output based on error.
 */

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController {
private:
    float _kp, _ki;
    float _cumError, _lastError;
    unsigned long _previousTime;

public:
    PIDController(float kp, float ki);
    float update(float setpoint, float measuredValue);
};

#endif