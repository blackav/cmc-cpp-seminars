#include <iostream>

using namespace std;

struct A
{
    virtual void f(int a, int b = 10)
    {
        cout << "A::f(int, double = " << b << ")" << endl;
    }
};

struct B : A
{
    void f(int a, int b = 20) override
    {
        cout << "B::f(int, int = " << b << ")" << endl;
    }
    virtual void f(double)
    {
        cout << "B::f(double)" << endl;
    }
};

int main()
{
    A a;
    B b;

    a.f(10);
    a.f(100, 200);
    b.f(20);
    b.f(1000, 2000);

    A *pa = &b;
    pa->f(10);
    pa->f(100, 200);
    pa->f(1.0);
}
