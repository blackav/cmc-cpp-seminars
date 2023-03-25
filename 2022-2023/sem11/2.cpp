#include <iostream>
#include <type_traits>

using namespace std;

int main()
{
    int y = 100;

    const int y2 = 1000;

    int &y3 = y;

    auto x = y;
    auto x2 = y2;

    auto x3 = y3;

    decltype(y3) x4 = y3;

    cout << is_reference<decltype(x3)>::value << endl;
    cout << is_reference<decltype(x4)>::value << endl;
    cout << is_const<decltype(x2)>::value << endl;
    //cout << is_reference<decltype(auto(x4))>::value << endl;
}

// T a = b;
// T a = (b);
