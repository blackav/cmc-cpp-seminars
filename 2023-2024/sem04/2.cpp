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
f()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
ff(int a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
f(double a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
f(const char *s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}
void
f(int *s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
ff(std::string s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
ff(bool a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
f(int a, int b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
f(A a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void
f(B a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

/*
void f(...)
{
        cout << __PRETTY_FUNCTION__ << endl;
}
*/

/*
void f(nullptr_t a)
{
        cout << __PRETTY_FUNCTION__ << endl;
}
*/

int
main()
{
    f();
    // f(1);
    f(1, 2);
    // f(1.6f);
    // f('x');
    // f(false);

    // f(1.5L);
    // f(1U);
    f(A{});
    // f(std::string("aassa"));
    f("12312");
    // f(nullptr);
    f(0);
}
