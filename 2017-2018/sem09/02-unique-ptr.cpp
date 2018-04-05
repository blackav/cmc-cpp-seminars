#include <memory>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct A
{
    int f = 0;
    double g = 0;
    A(int f) : f(f)
    {
        cout << "A(int)" << endl;
    }
    A(int f, double g) : f(f), g(g)
    {
        cout << "A(int, double)" << endl;
    }
    A()
    {
        cout << "A()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }

    void print() const
    {
        cout << f <<  " " << g << endl;
    }
};

struct B
{
    int f = 0;
    B(int f = 0) : f(f)
    {
        cout << "B(int):" << f << endl;
    }
    B(const B &o) : f(o.f)
    {
        cout << "B(const B&):" << f << endl;
    }
    B(B &&o) : f(o.f)
    {
        cout << "B(B&&):" << f << endl;
        o.f = 0;
    }
    ~B()
    {
        cout << "~B():" << f << endl;
    }
};

int main()
{
    unique_ptr<A> up{new A};
    auto up2 = make_unique<A>();
    auto up3 = make_unique<A>(10);
    auto up4 = make_unique<A>(10, 5.0);

    auto up5 = move(up4);

    up->print();
    up5->print();

    if (!up4) {
        cout << "oops" << endl;
    } else  {
        up4->print();
    }

    up2.get()->print();

    vector<unique_ptr<A>> v;

    v.push_back(unique_ptr<A>(new A{1, 1}));
    v.push_back(move(up5));
    v.push_back(make_unique<A>(2, 2));
    v.emplace_back(new A{3, 3});

    for (const auto &p : v) {
        p->print();
    }

    vector<B> v2;


    //v2.push_back(B(1));
    //B b{2};
    //v2.push_back(b);
    //B b2{3};
    //v2.push_back(move(b2)); 
    v2.emplace_back(4);

    // unique ptr works with arrays
    {
        auto upa = unique_ptr<B[]>(new B[3]{100, 200, 300});
    }
    cout << "after array" << endl;
}
