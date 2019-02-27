struct S
{
    mutable int x;
};

#include <iostream>

using namespace std;

int main()
{
    const S z{10};

    cout << z.x << endl;

    ++z.x;
    cout << z.x << endl;
}
