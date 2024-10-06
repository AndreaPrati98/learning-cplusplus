#include <iostream>

using namespace std;

// like saying int *const, 'cause k is a pointer
constexpr int *k = nullptr;
constexpr int w = 30;

int main() {
    
    // both are const
    const int i = 0, j = 10;
    

    // w = 2; cannot be done, cause w is const.
    
}

