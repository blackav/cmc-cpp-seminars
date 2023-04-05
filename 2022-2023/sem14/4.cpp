#include <iostream>
#include <memory>

using std::cout, std::endl, std::unique_ptr, std::make_unique;

struct A
{
    void f(int)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct B
{
    void f(double)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct C : A, B
{
    using A::f;
    using B::f;
    void g()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    C c;

    c.g();
    c.A::f(1);
    c.B::f(1);
    c.f(1);
    c.f(1.5);
}
