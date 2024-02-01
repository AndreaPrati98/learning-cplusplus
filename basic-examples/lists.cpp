#include <iostream>

using namespace std;

class List_element 
{
    public:
        int data;
        List_element* nextElement;

        List_element(int n = 0, List_element* next = nullptr): data(n), nextElement(next) {}
};

class List
{
    public:
        List(): head(nullptr), cursor(nullptr) {}
        
        void prepend(int n)
        {
            // this case, the list is empty, the head points at nothing
            if(head == nullptr) {
                cursor = head = new List_element(n, head);
            } else {
                head = new List_element(n, head);
            }
        }

        int get_element() {return cursor -> data;}

        void advance() {cursor = cursor -> nextElement;}
        
        void print() {
            List_element* h = head; // Let's start from the beginning

            while(h != nullptr) {
                cout << h -> data << ', ';
                h = h->nextElement;
            }

            cout << "###" << endl;
        }

    private: 
        List_element* head;
        List_element* cursor;
};



int main() {
    return 0;
}