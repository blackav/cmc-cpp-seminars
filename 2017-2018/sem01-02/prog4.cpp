#include <iostream>

using namespace std;

constexpr int N = 20;

constexpr int ff(int p)
{
    int res = 1;
    for (int i = 1; i <= p; ++i)
        res *= i;
    return res;
}

int arr[N];
char arr2[ff(6)];

int main()
{
    cout << sizeof(arr) <<  " " << sizeof(arr2) << endl;
}
