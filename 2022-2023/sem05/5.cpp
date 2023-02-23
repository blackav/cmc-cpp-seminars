#include <iostream>

using std::cin, std::cout, std::endl;

struct A
{
    A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void g()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void g() const
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void h() &
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void h() const &
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void h() &&
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    A a;
    const A b;

    a.g();
    b.g();
    A().g();

    a.h();
    b.h();
    A().h();
}
