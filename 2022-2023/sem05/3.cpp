#include <iostream>

using std::cout, std::endl;

void f(int &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void f(const int &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void f(int &&a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    int a = 10;
    int &ra = a;

    const int b = 20;
    const int &crb = b;

    int &&rrc = 100;

    int &&xxx = std::move(a);

    f(a);
    f(ra);

    f(b);
    f(crb);

    f(100);
    f(a + crb);
    f(std::move(xxx));
    f(static_cast<int &&>(xxx));
}
