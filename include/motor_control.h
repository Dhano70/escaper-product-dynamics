/*
 * Header file for the MotorControl class.
 * Provides an interface to drive the DC motors via the Cytron driver.
 */

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

class MotorControl {
private:
    int _pwmPin, _dirPin;
public:
    MotorControl(int pwm, int dir);
    void drive(int speed);
};

#endif