#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream word_file("./files/data.txt");
    istream_iterator<string> start(word_file), end;

    // we are now pointing at the beginning of the file.
    vector<string> words(start, end);

    // automatically each white space set of chars makes the delimiter

    cout << " \n\nwords as read\n" ;
    for (const auto &str : words)
    {
        cout << str << "\t";
    }
    
    
    cout << " \n\nwords to lowercase\n" ;
    for (auto &str : words)
    {
        // here I use the transform method in order to cycle over the string str and convert every char to lowercase
        // notice I use the pass-by-reference, otherwise the conversion wouldn't work.   
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); } );
        
        cout << str << "\t";
    }
    cout << endl;



    sort(words.begin(), words.end());
    cout << " \n\nwords as read\n" ;
    for (auto str : words)
    {
        cout << str << "\t";
    }
    cout << endl;

    return 0;
}
