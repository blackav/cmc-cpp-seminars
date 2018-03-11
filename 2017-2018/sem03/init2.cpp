#include <iostream>

// POD-type (plain-old-data)
struct A
{
    int a, b;
    double c;
};

struct B
{
    int a, b;
    double c;
    double d{3.14};

    B(int a, int b, double c) : d{464}
    {
        this->a = a;
        B::b = b;
        B::c = c;
    }
    B(int a, int b_ = 10)
        : a(a), b{b_}, c{} 
    {
    }
    B()
        : B(123, 444, 666.0)
    {
        c = 13;
    }
    void print()
    {
        using std::cout;
        using std::endl;
        cout << a << " " << b << " " << c << " " << d << endl;
    }
};

int main()
{
    A a1 = { 100, 200, 300};
    A a2{300, 400, 500};
    A a3 = {.a = 5 };

    B b1 = B(1, 2, 3);
    B b2(1, 2, 3);

    B b3 = { 1, 2, 3};
    B b4{1, 2, 3};

    B b5(1, 2);
    //B b5;
    b5.print();
    B(100499).print();
    B{}.print();
}
