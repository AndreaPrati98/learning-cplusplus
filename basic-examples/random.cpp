#include <iostream>
#include <ctime>

using namespace std;

int main() {
    cout << "This is a try" << endl;
    srand(clock());

    cout << rand() << endl;

    return 0;
}
