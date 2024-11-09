#include <iostream>

using namespace std;

void without_iterator();

int main() {

    without_iterator();

    return 0;
}

void without_iterator() {
    vector<unsigned> scores(11,0);

    unsigned grade;
    while (cin >> grade) {
        if(grade <= 100)
            ++scores[grade/10];
        else
            cout << "Ignoring input" << endl;
    }

    for(const auto &el : scores) {
        cout << el << " ";
    }

    cout << endl;
}