#include <iostream>

using namespace std;

struct A
{
    void f(int a, int b = 10)
    {
        cout << "A::f(int, int)" << endl;
    }
};

struct B : A
{
    void f(int a, int b = 20)
    {
        cout << "B::f(int, int)" << endl;
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
}
