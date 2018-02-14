#include <iostream>

using namespace std;

auto func(auto a, auto b) -> decltype(a)
{
    if (a > 0) {
        return a * b;
    }
    return a + b;
}

auto main() -> int
{
    int a = 10, b = 20;
    cout << func(a, b) << endl;
    double c = 5.6, d = 6.2;
    cout << func(c, d) << endl;
    cout << func(a, d) << endl;
    cout << func('c', a) << endl;
    return 0;
}
