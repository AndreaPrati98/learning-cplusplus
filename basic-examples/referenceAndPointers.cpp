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

/**
 * @brief Here I show how the const references are actually working. 
 * It's important ot know that most of the time when a reference to constant is defined it actually is a reference of
 * a temporary object created by the compiler. 
 * 
 * Example
 * 
 * double dval = 3.14;
 * const int &ri = dval;
 * 
 * actually is compiled into something like:
 * 
 * const int temp = dval;
 * const int &ref = temp;
 * 
 * And this makes sense, but actually could lead to problems.
 *
 * Moreover:
 * 
 * int &ri = dval;
 *
 * This is not possible because the compiler would not create a temp int variable to put dval,
 * indeed, the programmer creates the ref ri to be able to modify dval through the reference.
 * @return int 
 */
void constReferences() {
    cout << "Exec constReferences()" << endl;
    // ALLOWED BUT BAD
    double dval = 3.14;
    const int &ri = dval;
    cout << ri << endl;

    // NOT ALLOWED
    // int &ri = dval;
}

int main() {
    int i = 47, j = 12;
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

    void *voidP = &i; // void pointer can point to whatever
    double d = 3.14;
    voidP = &d;

    // Let's see also a reference to a pointer int
    int *&k = pointer; // the trick is to read from right to left
    // k and pointer are the same object now. 

    cout << endl;
    int *pointer2 = &j;
    cout << "Printing pointer2's value: \t" << pointer2 << endl;
    cout << "Printing k's value: \t\t" << k << endl;
    cout << "Printing pointer's value: \t" << pointer << endl;
    k = pointer2;
    cout << endl;
    cout << "Printing pointer2's value: \t" << pointer2 << endl;
    cout << "Printing k's value: \t\t" << k << endl;
    cout << "Printing pointer's value: \t" << pointer << endl;

    // of course, it's true we cannot change a reference but we can change the value of the reference
    // and thus the original object we are referencing.

    // one of the exception in which type of reference != type of the object referenced
    // is the const
    int z = 41;
    const int &ref = z;

    // moreover
    const int &badRef = d; // feasible, but wrong and dangerous

    return 0; // success
}



