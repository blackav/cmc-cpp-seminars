#include <iostream>

using namespace std;

struct A
{
    int a{10}, b{20};

    void f()
    {
        cout << a << " " << b << endl;
    }
    
};

struct B : public A
{
    int a{30}, c{40};

    void f()
    {
        cout << A::a << " " << b << " " << c << endl;
    }
};

int main()
{
    A a;
    B b;

    b.f();
    a.f();
}
