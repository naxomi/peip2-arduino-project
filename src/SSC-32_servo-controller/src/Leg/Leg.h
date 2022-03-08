// Copyright (c) 2022-2022. ANJOU Raphaël & DURAND Hugo
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file Leg.h
 *
 * @brief Leg object used to control one leg of the robot
 *
 * @author ANJOU Raphael
 * <p>
 * Contact: anjou.raphael\@gmail.com
 *
 */

#ifndef LEG_H
#define LEG_H

#include <Arduino.h>
#include "CustomServo/CustomServo.h"

/**
 * A {@code Leg} object allows you to control one of the robot leg.
 *
 * The leg that is controlled can be chosen when initializing with the parameter {@code leg_number}
 *
 * There are many constants and they are all specific to a certain leg.
 * Some are used to calculate correctly the angle to go to for the servos.
 * Some are used to assign which servos are used by the leg.
 *
 * @author ANJOU Raphael
 */
class Leg
{
public:
    /**
     * This method is the {@code Leg} initializer
     * @param leg_number The leg chosen, this value will affects which servos and constants are used
     */
    Leg(int leg_number);
    Leg();
    /**
     * This method will move the knee servo to the correct angle by considering the offsets constants
     * @param angle The desired angle to move the servo to
     */
    void move_knee(int angle);

    /**
     * This method will move the hip servo to the correct angle by considering the offsets constants
     * @param angle The desired angle to move the servo to
     */
    void move_hip(int angle);

    /**
     * This method will move the shoulder servo to the correct angle by considering the min and max constants
     * @param angle The desired angle to move the servo to
     */
    void move_shoulder(int angle);

    // Constants for LEG A
    int OFFSET_KNEE_A = 165;
    int OFFSET_HIP_A = 165;
    int ANGLE_MIN_SHOULDER_A = -40;
    int ANGLE_MAX_SHOULDER_A = 132;
    CustomServo SERVO_SHOULDER_A = CustomServo(8);
    CustomServo SERVO_HIP_A = CustomServo(9);
    CustomServo SERVO_KNEE_A = CustomServo(10);

    // Constants for LEG B
    int OFFSET_KNEE_B = 0;
    int OFFSET_HIP_B = -25;
    int ANGLE_MIN_SHOULDER_B = 165;
    int ANGLE_MAX_SHOULDER_B = -15;
    CustomServo SERVO_SHOULDER_B = CustomServo(24);
    CustomServo SERVO_HIP_B = CustomServo(25);
    CustomServo SERVO_KNEE_B = CustomServo(26);

    // Constants for LEG C
    int OFFSET_KNEE_C = 0;
    int OFFSET_HIP_C = 0;
    int ANGLE_MIN_SHOULDER_C = 60;
    int ANGLE_MAX_SHOULDER_C = 250;
    CustomServo SERVO_SHOULDER_C = CustomServo(23);
    CustomServo SERVO_HIP_C = CustomServo(22);
    CustomServo SERVO_KNEE_C = CustomServo(21);

    // Constants for LEG D
    int OFFSET_KNEE_D = 165;
    int OFFSET_HIP_D = 165;
    int ANGLE_MIN_SHOULDER_D = 180;
    int ANGLE_MAX_SHOULDER_D = 0;
    CustomServo SERVO_SHOULDER_D = CustomServo(7);
    CustomServo SERVO_HIP_D = CustomServo(6);
    CustomServo SERVO_KNEE_D = CustomServo(5);

private:
    int _leg_number;
    int _knee_offset;
    int _hip_offset;
    int _ANGLE_MIN_SHOULDER;
    int _ANGLE_MAX_SHOULDER;
    CustomServo _knee_servo;
    CustomServo _hip_servo;
    CustomServo _shoulder_servo;
};
#endif