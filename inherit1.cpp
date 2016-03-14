#include <iostream>

using namespace std;

class A
{
public:
    void f(int a) { cout << "A::f(int)\n"; }
    void f(double a) { cout << "A::f(double)\n"; }
};

class B : public A
{
public:
    using A::f;
    void f(char a) { cout << "B::f(char)\n"; }
};

int main()
{
    B b;
    A &a = b;

    b.f(1);
    a.f(1.0);
    //b.f(1L);
}
