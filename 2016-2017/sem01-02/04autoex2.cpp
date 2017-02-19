#include <iostream>

using namespace std;

auto func(auto a, auto b) -> auto
{
    return a + b;
}

int main()
{
    cout << func(2, 3) << endl;
    cout << func(2.0, 3.1) << endl;
    cout << func(2U, 3.5) << endl;
    cout << func(2.2, 3U) << endl;
}
