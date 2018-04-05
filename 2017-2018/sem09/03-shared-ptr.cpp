#include <iostream>
#include <memory>

using namespace std;

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
    void print()
    {
        cout << f << endl;
    }
};

auto func(auto p)
{
    p->print();
    cout << p.use_count() << endl;
    return p;
}

struct C
{
    B b;
    shared_ptr<C> c;

    C(const B&b, const shared_ptr<C> &c = shared_ptr<C>{}) : b(b), c(c) {}
};

int main()
{
    shared_ptr<B> sp(new B(1));
    auto sp2 = sp;

    sp->print();
    sp2->print();
    auto sp3 = func(sp2);

    weak_ptr<B> wp;
    shared_ptr<B> sp5;
    {
        shared_ptr<B> sp4(new B(2));

        wp = sp4;
        sp5 = sp4;
        wp.lock()->print();
    }
    cout << "out" << endl;
    auto sp7 = wp.lock();
    if (!sp7) {
        cout << "bad" << endl;
    } else {
        sp7->print();
    }

    cout << "before circular list" << endl;
    {
        // make circular list
        shared_ptr<C> pc1(new C{B(1)});
        shared_ptr<C> pc2(new C{B(2), pc1});
        pc1->c = shared_ptr<C>(pc2);

        // make 10 iterations over the list
        shared_ptr<C> p = pc1;
        for (int i = 0; i < 10 && p; ++i) {
            p->b.print();
            p = p->c;
        }
    }
    cout << "after circular list" << endl;
}
