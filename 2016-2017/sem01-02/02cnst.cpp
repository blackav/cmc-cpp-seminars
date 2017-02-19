#include <iostream>

using namespace std;

constexpr int N = 20;

constexpr int ff(int x)
{
    return (x <= 0)?1:ff(x - 1)*x;
}

int main()
{
    cout << sizeof(int[ff(6)]) << endl;
}
