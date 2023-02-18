#include <iostream>

using std::cin, std::cout, std::endl;

struct A
{
    A(int a = 0)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    explicit operator bool() const
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return false;
    }
};

int main()
{
    A a;

    //int b = a;

    if (a) {
    }
    if (1 && a) {
    }
}
