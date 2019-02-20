#include <iostream>

using namespace std;

struct B
{
    int b;

    B(int b) : b(b) {}
};

struct A
{
private:
    int a;

public:
    A(int a) : a(a) {}
    A(const B&b) : a(10)
    {
        cout << "A::A(const B&)" << endl;
    }

    int operator + () const
    {
        cout << "A::operator +()" << endl;
        return a;
    }

    int operator -() const;

    int operator + (const A& a) const
    {
        cout << "A::operator +(const A&)" << endl;
        return 0;
    }
};

int A::operator -() const
{
    cout << "A::operator -()" << endl;
    return -a;
}

int operator !(const A &a)
{
    cout << "operator !(const A&)" << endl;
    return 1;
}

int operator -(const A &a, const A&b)
{
    cout << "operator-(const A&, const A&)" << endl;
    return 0;
}

int main()
{
    A a(1), a2(2);
    +a;
    -a;
    !a;

    a + a2;
    a - a2;

    B b(2);
    !b;

    a + b;

    //b + a;

    a - b;
    b - a;
    b - b;
}
