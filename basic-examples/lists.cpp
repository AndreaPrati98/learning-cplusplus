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
        
        List(const List& lst) {
            
            cout << "Using copy constructor" << endl;

            if(lst.head == nullptr) {
                
                // the list we are trying to copy is just an empty list
                head = nullptr;
                cursor = nullptr;

            } else {
                
                List_element* h = new List_element();
                List_element* previous;

                this -> head = h; // the head of this list points to the new list element
                h -> data = lst.head -> data; // fill the data of the list element at the head of our list
                previous = h; // memorize that the element we just filled will be the previous of the next one

                this -> cursor = lst.head -> nextElement; // with the cursor we need to point at the next element
                while( cursor != nullptr ) { // it's a for but if could also just be a while
                    
                    h = new List_element();

                    h -> data = cursor -> data;
                    previous -> nextElement = h;
                    
                    this -> cursor = this -> cursor -> nextElement;
                    previous = h;
                }
                cursor = head;
            }

            cout << "End of the copy." << endl;
        }

        ~List() {
            cout << "Destructor executed" << endl;
        }

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
                cout << h -> data << ", ";
                h = h -> nextElement;
            }

            cout << "###" << endl;
        }

    private: 
        List_element* head;
        List_element* cursor;
};


int main() {
    List a, b;

    a.prepend(9);
    a.prepend(8);

    cout << "List a: " << endl;
    a.print();

    for (int i = 0; i < 10; i++) 
    {
        b.prepend(i*i);
    }

    cout << "List b: " << endl; 
    b.print();

    cout << endl;

    // List* c = new List(b);
    List c = List(b);
    
    cout << "List c: " << endl; 
    c.print();

    

    return 0;
}