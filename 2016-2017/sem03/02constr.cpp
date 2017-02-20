#include <iostream>

using namespace std;

struct Foo
{
    int f1 = 2;
    double f2{5.5};

    Foo() = default;
    Foo(int f1, double f2 = 7.7)
    {
        Foo::f1 = f1;
        this->f2 = f2;
    }
    Foo(const Foo &other)
        : f1(other.f1), f2(other.f2)
    {
        cout << "Foo " << (void*) this << " " << (void*) &other << endl;
    }

    auto print() -> auto
    {
        cout << f1 << " " << f2 << endl;
    }
};

auto func1(Foo z) -> auto
{
    z.print();
}

auto func2() -> Foo
{
    Foo z{25, 36};
    z.print();
    return *new Foo{44, 55};
}

int main()
{
    Foo a;
    a.print();

    Foo b(4);
    b.print();

    Foo c{7, 3.3};
    c.print();

    Foo d{c};
    d.print();

    func1(b);

    Foo e = func2();
}
