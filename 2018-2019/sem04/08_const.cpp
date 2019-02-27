constexpr int N = 10;
int arr[N];

constexpr int f(int a)
{
    if (a <= 0) return 1;
    return a * f(a - 1);
}

char c[f(N)]{1};

#include <iostream>

using namespace std;

int main()
{
    cout << sizeof(c) << endl;
}
