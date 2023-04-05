#include <iostream>
#include <memory>

using std::cout, std::endl, std::unique_ptr, std::make_unique;

struct A
{
    int x{};
    A(int x_ = 3) : x(x_) {}
    void f()
    {
        cout << x << endl;
    }
};

struct B : virtual A
{
    B() : A(1) {}
};

struct C : virtual A
{
    C() : A(2) {}
};

struct D : B, C
{
    void g()
    {
        B::f();
        C::f();
    }
};


int main()
{
    D d;

    d.B::f();
    d.C::f();
    d.g();
}
