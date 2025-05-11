#include <iostream>

using namespace std;

enum States {
    NotReady,
    Ready,
    Running,
    Paused,
    Stopped
};

int main() {
    const States states[] = {
        States::NotReady, 
        States::Paused, 
        States::Ready, 
        States::Running, 
        States::Stopped
    };
       
    for(const States *i = begin(states); i != end(states); ++i) {
        cout << *i << endl;
    }
    

    cout << "end" << endl;
    return 0;
}