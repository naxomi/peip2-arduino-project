#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include "CustomServos/CustomServos.h"

class PolyDog
{
public:
    PolyDog(); // Default construteur
    void start();
    void forward_leg(int leg_number, int step);
    void hold_shoulders();
    void move_forward();
    void control_from_dog();

private:
    CustomServos _servoEpauleA;
    CustomServos _servoHancheA;
    CustomServos _servoGenouA;

    CustomServos _servoEpauleB;
    CustomServos _servoHancheB;
    CustomServos _servoGenouB;

    CustomServos _servoEpauleC;
    CustomServos _servoHancheC;
    CustomServos _servoGenouC;

    CustomServos _servoEpauleD;
    CustomServos _servoHancheD;
    CustomServos _servoGenouD;
};

#endif