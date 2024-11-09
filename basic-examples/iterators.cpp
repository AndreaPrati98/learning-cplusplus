#include <iostream>

using namespace std;

void without_iterator();
void with_iterator();

int main() {

    cout << "Without iterator" << endl;
    without_iterator();
    cout << "With iterator" << endl;
    with_iterator();

    return 0;
}

void without_iterator() {
    vector<unsigned> scores(11,0);

    unsigned grade;
    while (cin >> grade && grade < 100) {
        ++scores[grade/10];
    }

    for(const auto &el : scores) {
        cout << el << " ";
    }

    cout << endl;
}

void with_iterator() {
    vector<unsigned> scores(11,0);

    unsigned grade;
    while (cin >> grade && grade < 100) {
        auto scores_iterator = scores.begin();
        scores_iterator += grade/10;
        ++(*scores_iterator);
    }

    for(const auto &el : scores) {
        cout << el << " ";
    }

    cout << endl;
}

void power_per_element() {
    vector<int> vec(10);

    for(auto vec_iterator = vec.begin();
            vec_iterator != vec.end();
            ++vec_iterator) 
    {
        *vec_iterator *= 2;
    }
}
