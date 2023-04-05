#include <iostream>
#include <memory>

using std::cout, std::endl, std::unique_ptr, std::make_unique;

struct A
{
    int x{10};
    virtual void f(double)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << x << endl;
    }
};

struct B
{
    int y{20};
    virtual void f()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << y << endl;
    }
};

struct C : A, B
{
    virtual void g()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    C *pc = new C();

    A *pa = pc;
    B *pb = pc;

    pa->f(1);
    pb->f();

    C *pc1 = static_cast<C*>(pa); 
    pc1->g();

    C *pc2 = static_cast<C*>(pb); 
    pc2->g();

    void *pv = pc;
    B *pb2 = static_cast<B*>(pv);
    pb2->f();

    C *pc3 = static_cast<C*>(pb2);
    pc3->g();
}
