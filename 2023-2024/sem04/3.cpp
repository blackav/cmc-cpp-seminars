#include <iostream>
#include <string>

using std::cout, std::endl;

struct A
{
    int a_{};

    A() = default;
    A(int a) noexcept : a_(a) { cout << __PRETTY_FUNCTION__ << endl; }
    A(std::string x) { cout << __PRETTY_FUNCTION__ << endl; }

    explicit operator bool() const noexcept
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return bool(a_);
    }
};

struct B
{
    int a_{};

    B() = default;
    B(int a) noexcept : a_(a) { cout << __PRETTY_FUNCTION__ << endl; }
    B(std::string x) { cout << __PRETTY_FUNCTION__ << endl; }
};

void
f(int a, int b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
f(double a, double b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int
main()
{
    f(1, 1);
    f(1.0, 1.0);

    f(1u, 1);
    f(1u, 1.0);
    // f(1u, 1u);
    f(1u, 'a');
    f(1u, 1.0f);
    // f('a', 1.0f);
}
