#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct A
{
    int a;
    static int b;

    A() : a(22) {}

    void f() // A* this
    {
        cout << __PRETTY_FUNCTION__ << endl;
        ++b;
    }
    static void g()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        ++b;
    }
};

int A::b = 1111;

int main()
{
    A a;
    A a2;

    a.f();
    a.g();
    a2.g();

    A::g();
    A().g();

    cout << A::b << endl;
    cout << sizeof(a) << endl;
}
