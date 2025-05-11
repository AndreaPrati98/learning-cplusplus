#ifndef LIGHT_H
#define LIGHT_H

#include "iostream"
#include "LightState.h"

using namespace std;

class Light
{
private:
    // using uniform initialization to prevent unwanted conversions
    FSM_Definitions::LightState currentState {FSM_Definitions::LightState::Off};
public:
    Light();
    ~Light();

    void toggle();
    void printState(ostream &stream); 
};


#endif