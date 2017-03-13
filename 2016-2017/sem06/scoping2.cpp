#include <iostream>

using namespace std;

struct A
{
    void f(char c)
    {
        cout << "A::f(char)" << endl;
    }
    void f(double d)
    {
        cout << "A::f(double)" << endl;
    }
};

struct B: A
{
    void f(int i)
    {
        cout << "B::f(int)" << endl;
    }
/*
    void f(double d)
    {
        A::f(d);
    }
*/
    using A::f;
};

int main()
{
    A a;
    B b;

    a.f('a');
    a.f(1.0);
    a.f(1.2f); 
    //a.f(10);
    b.f('a');
    b.f(1.0);
    b.f(1.2f); 
    b.f(10);
}
