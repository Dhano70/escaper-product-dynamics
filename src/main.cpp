/*
 * Main execution file for the Escaper robot.
 * This file coordinates the ultrasonic distance sensing, PI control logic, 
 * and motor actuation to maintain a safe distance from obstacles.
 */

#include <Arduino.h>
#include "robot_config.h"
#include "pid_controller.h"
#include "motor_control.h"

PIDController pid(KP, KI);
MotorControl leftMotor(MOTOR_L_PWM, MOTOR_L_DIR);
MotorControl rightMotor(MOTOR_R_PWM, MOTOR_R_DIR);

void setup() {
    Serial.begin(9600);

    // Setup ultrasonic sensor pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    // Read distance from ultrasonic sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = duration * 0.034 / 2;

    // Calculate motor speed output based on 20cm target
    float output = pid.update(20.0, distance);

    // Keep PWM within hardware limits (50-255)
    int finalSpeed = (int)constrain(output, 50, 255);

    // Drive motors based on PID output
    leftMotor.drive(finalSpeed);
    rightMotor.drive(finalSpeed);

    delay(200); 
}