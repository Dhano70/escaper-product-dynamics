/*
 * Configuration file containing hardware pin assignments 
 * and calibrated PID constants for the Escaper robot.
 */

#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

// Hardware pin assignments
const int MOTOR_L_PWM = 5;
const int MOTOR_L_DIR = 6;
const int MOTOR_R_PWM = 10;
const int MOTOR_R_DIR = 11;

const int TRIG_PIN = 7;
const int ECHO_PIN = 8;

// Controller constants
const float KP = 0.18;
const float KI = 0.864;

#endif