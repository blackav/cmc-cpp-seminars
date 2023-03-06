#include <iostream>
#include <memory>

using std::cout, std::endl, std::move, std::unique_ptr, std::make_unique;

struct A
{
    int v{};

    A(int vv = 0) : v(vv)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~A()
    {
    
        cout << __PRETTY_FUNCTION__ << ":" << v << endl;
    }
};

unique_ptr<A> f(unique_ptr<A> p)
{
    cout << "f: " << p->v << endl;

    return move(p);
}

int main()
{
    unique_ptr<A> up(new A(100));

    {
        auto res = f(move(up));
    }

    auto up2 = make_unique<A>(101);

    unique_ptr<A[]> up3(new A[4]{200, 201, 202, 203});

    auto up4 = make_unique<A[]>(4);
}
