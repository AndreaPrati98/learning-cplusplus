#include <iostream>

class List_element 
{
    public:
        int data;
        List_element* nextElement;

        List_element(int n = 0, List_element* next = nullptr): data(n), nextElement(next) {}
};

int main() 
{
    return 0;
}