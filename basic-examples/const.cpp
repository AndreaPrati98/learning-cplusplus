#include <iostream>

using namespace std;

/*
    Need to remember that when we speak about an object and if it is const or not we need to think
    not about the syntax but the nature itself in memory.

    To explain myself better, we can say:
    - TOP-level const
    - LOW-leve const

    The first one refers to the object itself (constant integer, constant pointer and so on). When we talk about LOW-level
    const we are talking about compound types, most of the times. Indeed, low-level is in the sens that the type they, somehoe,
    holds are constant. 

    const int *p;

    Here p HAS (it not that it is or not, it's about it has or not) a low-level const.

    It is important to think about it when we copy objects, if the first object we are copying from has a low-level const, then
    the object we are copying to must also have the low level const.

*/

// like saying int *const, 'cause k is a pointer
constexpr int *k = nullptr;
constexpr int w = 30;

int main() {
    
    // both are const
    const int i = 0, j = 10;
    

    // w = 2; cannot be done, cause w is const.
    
}

