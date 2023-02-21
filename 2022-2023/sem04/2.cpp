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

    void f() // A* this
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << a << endl;
        ++a;
        cout << this->a << endl;
    }
    void f() const; // const A *this
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

void A::f() const
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << a << endl;
    //++((A*) this)->a;
    //++const_cast<A*>(this)->a;
    //cout << this->a << endl;
}

namespace
{
    A a0;
    const A a4;
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

    const A a3;
    a3.f();
    a4.f();
}
