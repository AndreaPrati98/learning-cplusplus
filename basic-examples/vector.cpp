#include <iostream>

using namespace std;

int main() {

    vector<int> arr;

    for (int i = 1; i <= 5; i++)
        arr.push_back(i);

    
    cout << "Ciao: " << arr.back() << endl;
    
    // cout << "Ciao: " <<  << endl;

    return 0;
}