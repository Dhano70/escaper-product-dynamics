/*
 * Implementation of the PI control logic.
 * Calculates the correction signal using proportional and integral terms.
 */

#include "pid_controller.h"
#include <Arduino.h>

PIDController::PIDController(float kp, float ki) 
    : _kp(kp), _ki(ki), _cumError(0), _lastError(0) {
    _previousTime = millis();
}

float PIDController::update(float setpoint, float measuredValue) {
    unsigned long currentTime = millis();
    float elapsedTime = (float)(currentTime - _previousTime) / 1000.0;
    
    // Calculate error and accumulate it for the integral term
    float error = setpoint - measuredValue;
    _cumError += error * elapsedTime;
    
    // Standard PI calculation
    float output = (_kp * error) + (_ki * _cumError);

    _lastError = error;
    _previousTime = currentTime;

    return output;
}