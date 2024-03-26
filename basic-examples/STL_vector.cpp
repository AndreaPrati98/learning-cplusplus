#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> v(15); // vector is a template and is a random access container
    // it replaces arrays in c++

    // now let's show two ways of doing for loops 
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }

    // this is more c++ style
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "\t";
    }

    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << "\t";
    }

    cout << endl;

    return 0;
}
