#include <iostream>

using namespace std;

int main() {
    
    vector<unsigned> scores(11,0);

    unsigned grade;
    while (cin >> grade) {
        if(grade < 100)
            ++scores[grade/10];
    }

    for(const auto &el : scores) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}