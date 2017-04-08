#include <iostream>

using namespace std;

struct A
{
    void print_this()
    {
        cout << "D: " << (void*) this << endl;
    }

    virtual void f()
    {
        cout << "A::f" << endl;
    }
};

struct B : A
{
    double z;
    void f()
    {
        cout << "B::f" << endl;
    }
};

struct C : A
{
    void f()
    {
        cout << "C::f" << endl;
    }
};

struct D : B, C
{
    void print_this()
    {
        cout << "D: " << (void*) this << endl;
    }
};

int main()
{
    D d;
    d.print_this();
    d.B::print_this();
    d.C::print_this();

    D *pd = &d;
    B *pb = pd;
    C *pc = pd;

    cout << "D*: " << pd << endl;
    cout << "B*: " << pb << endl;
    cout << "C*: " << pc << endl;

    D *pd2 = reinterpret_cast<D*>(pc);
    cout << "D2*: " << pd2 << endl;

    void *pv = pd;
    C *pc2 = (C*) pv;
    cout << "C2*: " << pc2 << endl;

    pc->f();
    //pc2->f();
}


