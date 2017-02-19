#include <iostream>

using namespace std;

struct A
{
    int a;
};

struct B : A
{
    virtual void f() { cout << "B::f()" << endl; }
};

struct C : A
{
    virtual void f() { cout << "C::f()" << endl; }
};

struct D : B, C
{
};

int main()
{
    D d;
    cin >> d.C::a;
    d.B::f();
}
