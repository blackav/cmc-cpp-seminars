#include <iostream>

void f(int a, int b)
{
    std::cout << "f(int, int)" << std::endl;
}

void f(double a, double b)
{
    std::cout << "f(double, double)" << std::endl;
}

void f(const char *a, double b)
{
    std::cout << "f(const char *, double)" << std::endl;
}

struct A
{
    A(int z)
    {
        std::cout << "A::A(int)" << std::endl;
    }
    A(long z)
    {
        std::cout << "A::A(long)" << std::endl;
    }

    explicit A(double z)
    {
        std::cout << "A::A(double)" << std::endl;
    }

    operator const char *() const
    {
        std::cout << "operator const char *" << std::endl;
        return "OK";
    }

    operator int() const
    {
        std::cout << "operator int" << std::endl;
        return 1;
    }
};

void f(const A &a)
{
    std::cout << "f(const A&)" << std::endl;
}

void g(double z)
{
    std::cout << "g(double)" << std::endl;
}

int main()
{
    f(1, 2);
    f(1.3, 2.3);

    f(nullptr, 2.0);

    short z;
    f(z, 1);

    f(10);
    f(z);
    f(A(1.4));

    A a{1.5};
    f(a, 1);
    g(a);
}
