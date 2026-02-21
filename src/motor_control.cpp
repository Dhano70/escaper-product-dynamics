/*
 * Implementation of motor driving logic.
 * Handles PWM signals and direction switching for the hardware.
 */

#include "motor_control.h"
#include <Arduino.h>

MotorControl::MotorControl(int pwm, int dir) : _pwmPin(pwm), _dirPin(dir) {
    pinMode(_pwmPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
}

void MotorControl::drive(int speed) {
    // Set direction based on positive/negative speed
    if (speed >= 0) {
        digitalWrite(_dirPin, HIGH);
    } else {
        digitalWrite(_dirPin, LOW);
    }

    // Apply PWM power
    analogWrite(_pwmPin, abs(speed));
}