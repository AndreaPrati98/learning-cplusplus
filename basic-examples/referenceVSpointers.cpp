#include <iostream>

using namespace std;

/* 
    The point of this file is to remember the existance of compound types, which
    is a type that is defined in terms of another.

    The idea is that there are several, but here we see just two:
    - reference 
    - pointers

    The reference is an actual copy of the variable, is not an object per-se, which means that if we 
    consider the scrip below, i and reference are exactly the same thing, and there is no way to make the reference "change reference".
    On the other side, the pointer is an object per-se, it can point to whatever we want and change whenever we want.
    
*/

int main() {
    int i = 47;
    int &reference = i;
    int *pointer = &i;

    cout << "Printing i: \t" << i << endl;
    cout << "Printing reference: \t" << reference << endl;
    cout << "Printing what pointer is pointing to: \t" << *pointer << endl;
    cout << endl;
    cout << "Printing pointer's value: \t" << pointer << endl;
    cout << "Printing reference's address: \t" << &reference << endl; 
    cout << "Printing i's address; \t\t" << &i << endl; 


    cout << "Printing pointer's address: \t" << &pointer << endl;
    
    return 0; // success
}

