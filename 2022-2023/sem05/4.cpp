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
    void g() const
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

const A &f(const A &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return a;
}

const A &f(A &&a) = delete;

int main()
{
    const A &ra = f(A());
}
