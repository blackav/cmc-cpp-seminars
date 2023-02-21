#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct A
{
    int a = 22;
    static int b;

    static const int c = 1212;
    static constexpr int d = 2345;
    static inline int e = 100;

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
    cout << A::c << endl;
    cout << A::d << endl;
    cout << ++A::e << endl;
}
