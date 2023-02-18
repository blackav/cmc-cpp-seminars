#include <iostream>

using std::cin, std::cout, std::endl;

void f(int a, int b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(int a = 10)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << a << endl;
}

void h();

int main()
{
    f(1, 2);
    g();
    g(100);
    h();
}
