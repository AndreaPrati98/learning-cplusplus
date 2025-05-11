#include "Light.h"

Light::Light()
{
    std::cout << "Constructor Light class" <<std::endl;
}

Light::~Light()
{
    std::cout << "Destructor Light class" <<std::endl;
}

void Light::toggle() {
    this -> printState(cout);
    this -> currentState = FSM_Definitions::lightTransitions[this -> currentState];
    this -> printState(cout);

}

void Light::printState(ostream &stream) 
{
    int stateToInt = static_cast<int>(this -> currentState);
    stream << "Current state is: " << stateToInt << endl;
}