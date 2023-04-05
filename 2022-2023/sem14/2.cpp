#include <iostream>
#include <memory>

using std::cout, std::endl, std::unique_ptr, std::make_unique;

struct A
{
    virtual void f(int x, int y = 10)
    {
        cout << __PRETTY_FUNCTION__ << ", " << y << endl;
    }
    virtual ~A() = default;
};

struct B : public A
{
    void f(int x, int y = 20) override
    {
        cout << __PRETTY_FUNCTION__ << ", " << y << endl;
    }
};

int main()
{
    A a;
    B b;

    a.f(1);
    b.f(1);

    auto pa1 = make_unique<A>();
    unique_ptr<A> pa2 = make_unique<B>();
    auto pb = make_unique<B>();

    pa1->f(1);
    pa2->f(1);
    pb->f(1);
}
