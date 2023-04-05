#include <iostream>
#include <memory>

using std::cout, std::endl, std::unique_ptr, std::make_unique;

class A
{
private:
    void f(int x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
public:
    void f(double x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void g()
    {
        f(1);
        f(1.2);
    }
};

int main()
{
    A a;

    a.g();

    a.f(1);
    a.f(1.2);
}
