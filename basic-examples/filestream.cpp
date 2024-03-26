#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream data_file("./files/data.txt");
    istream_iterator<int> start(data_file), end;

    // we are now pointing at the beginning of the file.
    vector<int> data(start, end);

    int sum = 0;
    for (auto it = start; it != end; ++it) {
        sum += *it;
    }

    cout << "Sum = " << sum << endl;
    cout << "average is = " << 1.0 * sum/data.size() << endl;
    

    return 0;
}
