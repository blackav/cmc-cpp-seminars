#include <iostream>

using std::cout, std::endl;

namespace
{
    int b = 100;
}

struct A
{
    int a = 1;
    int b = 2;

    void f() // A*
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << a << endl;
        ++a;
        cout << this->a << endl;
    }
    void g()
    {
        int b = 3;
        cout << __PRETTY_FUNCTION__ << endl;
        cout << b << endl;
        cout << this->b << endl;
        cout << (*this).b << endl;
        cout << A::b << endl;
        cout << ::b << endl;
    }
};

namespace
{
    A a0;
}

int main()
{
    A a1;
    A* a2 = new A;


    a0.f();
    a1.f();
    a2->f();

    A().g();

    a0.A::f();
    a2->A::f();
}
