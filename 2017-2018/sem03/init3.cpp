#include <iostream>

using namespace std;

struct A
{
    double a{}, b{};

/*
    A(){}
*/
    //A() {}
    explicit A(double a_) : a(a_) {}
    A() = default;
    //A() = delete;
    A(const A &) = delete;
    
    void print() const
    {
        cout << a <<  " " << b << endl;
    }
};

void f(const A &a)
{
    a.print();
}

int main()
{
    A a1 = A();
    a1.print();

    A ax{1.4};
    f(ax);
    f(5.5);
    f(100L);
/*
    A a2{a1};
    a2.print();
*/

/*
    A a3{1, 2};
    A a4{a3};
    a4.print();
*/
}
