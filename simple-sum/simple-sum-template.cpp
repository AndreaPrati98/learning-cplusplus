#include <iostream>
#include <ctime>


using namespace std;

#define N 40

template <typename summable>

void sum(summable &res, int size, const summable arr[]) 
{

    for (int i = 0; i < size; i++)
    {
        res += arr[i];
        // += must work for summable
    }
    
}

int main() 
{
    double res = 0;
    double arr[N];
    
    srand(clock()); // setting the seed for the random function


    for (int i = 0; i < N; i++)
    {
        arr[i] = rand()/static_cast<double>(rand());
    }
    
    sum(res, N, arr);

    cout << "The result is: " << res << endl;
    cout << clock() << endl;

    return 0;
}
