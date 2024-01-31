#include <iostream>
using namespace std;

const int N = 40;

void sum(int &res, int size, int arr[]) 
{

    for (int i = 0; i < size; i++)
    {
        res += arr[i];
    }
    
}

int main() 
{
    int res = 0;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }
    
    sum(res, N, arr);

    cout << "The result is: " << res << endl;
    return 0;
}
