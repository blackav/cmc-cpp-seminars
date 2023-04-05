#include <iostream>

using std::cout, std::endl;

struct A
{
    void f(int x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void f(const char *str)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct B : public A
{
    using A::f;
    void f(double x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    A a;
    B b;

    a.f(100);
    a.f(1.2);

    b.f(1.2);
    b.f(1000);
    b.f("asas");
}
