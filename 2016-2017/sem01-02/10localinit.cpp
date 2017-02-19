#include <iostream>

using namespace std;

int main()
{
    //int a; -- UNINITIALIZED
    //int a(); -- BAD!
    //int a = 5;
    //int a(6);
    //int a = int(7);
    //int a = int();
    //int a{23};
    int a{};

    cout << a << endl;

    bool x = false;
    bool y = true;
    x = 3;
    cout << x << " " << y << endl;
}
