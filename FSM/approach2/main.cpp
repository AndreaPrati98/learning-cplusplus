#include <iostream>
#include "Light.h"

using namespace std;

int main() {
    
    Light light;
    light.printState(cout);
    cout << endl;
    light.toggle();
    cout << endl;
    light.toggle();
    return 0;
}