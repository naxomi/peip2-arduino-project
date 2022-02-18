/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "PolyDog.h"

PolyDog::PolyDog() : _servoEpauleA(9),  // Epaule A
                     _servoHancheA(10), // Hanche A
                     _servoGenouA(11),  // Genou A
                     _servoEpauleB(25), // Epaule B
                     _servoHancheB(26), // Hanche B
                     _servoGenouB(27),  // Genou B
                     _servoEpauleC(22), // Epaule C
                     _servoHancheC(21), // Hanche C
                     _servoGenouC(19),  // Genou C
                     _servoEpauleD(7),  // Epaule D
                     _servoHancheD(5),  // Hanche D
                     _servoGenouD(4)    // Genou D

{
    // HOLDER
}

void PolyDog::forward_leg(int leg_number, int step)
{

    CustomServos servo_hanche;
    CustomServos servo_genou;

    int offset_genou;
    int offset_hanche;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    case 2: // LEG B
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 3: // LEG C
        servo_hanche = _servoHancheC;
        servo_genou = _servoGenouC;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheD;
        servo_genou = _servoGenouD;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    default:
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 0;
        offset_hanche = 0;
    }

    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen
    switch (step)
    {
    default:
    case 1:
        servo_hanche.write(abs(offset_hanche - 50));
        servo_genou.write(abs(offset_genou - 98));
        break;
    case 2:
        servo_genou.write(abs(offset_genou - 63));
        break;
    case 3:
        servo_hanche.write(abs(offset_hanche - 67));
        break;
    case 4:
        servo_genou.write(abs(offset_genou - 66));
        break;
    case 5:
        servo_genou.write(abs(offset_genou - 83));
        break;
    case 6:
        servo_genou.write(abs(offset_genou - 98));
        break;
    case 7:
        servo_hanche.write(abs(offset_hanche - 50));
    }
}

void PolyDog::move_forward()
{
    int number_of_stages = 8;
    int decalage_A = 0;
    int decalage_B = 4;
    int decalage_C = 0;
    int decalage_D = 4;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        this->forward_leg(1, (stage + decalage_A) % number_of_stages);
        this->forward_leg(2, (stage + decalage_B) % number_of_stages);
        this->forward_leg(3, (stage + decalage_C) % number_of_stages);
        this->forward_leg(4, (stage + decalage_D) % number_of_stages);

        delay(100);
    }
}

void PolyDog::hold_shoulders()
{
    _servoEpauleA.write(48);
    _servoEpauleB.write(79);
    _servoEpauleC.write(158);
    _servoEpauleD.write(89);
}

void PolyDog::start()
{

    // Start position
    _servoHancheA.write(abs(180 - 42));
    _servoGenouA.write(abs(180 - 85));

    _servoHancheB.write(abs(42));
    _servoGenouB.write(abs(85));

    _servoHancheC.write(abs(42));
    _servoGenouC.write(abs(85));

    _servoHancheD.write(abs(180 - 42));
    _servoGenouD.write(abs(180 - 85));

    this->hold_shoulders();
}
