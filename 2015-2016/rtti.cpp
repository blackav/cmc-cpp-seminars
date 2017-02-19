#include <iostream>
#include <typeinfo>

using namespace std;

struct A
{
    virtual ~A() {}
    virtual bool equals(const A *) const { return false; };
};

struct B : A
{
    bool equals(const A *pa) const override
    {
        const B *pb = dynamic_cast<const B*>(pa);
        if (!pb) return false;
        return false;
    }
};

struct C : B
{
};

struct D : A
{
};

int main()
{
    A *pa1 = new D;
    A *pa2 = new C;

    const type_info &t = typeid(*pa1);   
    auto &t2 = typeid(new C);

    cout << t.name() << endl;
    cout << t2.name() << endl;
    if (t == typeid(D)) {
        cout << "This is D" << endl;       
    }
    if (t2== typeid(C)) {
        cout << "This is C" << endl;
    }

    cout << static_cast<B*>(pa1) << endl;
    cout << static_cast<B*>(pa2) << endl;

    D dd;    
    A &ra = dd;
    dynamic_cast<B&>(ra);
}
