#include <iostream>
#include <memory>

using std::cout, std::endl;

struct A
{
    int v{};

    A(int vv = 0) : v(vv)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    A *p = new A;
    delete p;

    A *p2 = new A[4];
    delete[] p2;

    A *p3 = new A[4]{1, 2, 3, 4};
    delete[] p3;
}
