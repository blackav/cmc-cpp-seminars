#include <iostream>
#include <typeinfo>

using namespace std;

struct A
{
    virtual ~A() {}
};

struct B : A
{
};

void f(A *p)
{
    B *pb = dynamic_cast<B*>(p);
    cout << pb << endl;
    cout << typeid(dynamic_cast<B*>(p)).name() << endl;
    B *pb2 = static_cast<B*>(p);
    cout << pb2 << endl;
}

void g(A &r)
{
    try {
        B &rb = dynamic_cast<B&>(r);
    } catch (const std::bad_cast &e) {
        cout << e.what() << endl;
        cout << "ok" << endl;
    }
}

int main()
{
    A *pa = new B;

    const type_info &ti = typeid(*pa);
    cout << ti.name() << endl;
    f(pa);
    f(new A);
    f(nullptr);
    g(*pa);
    A z;
    g(z);
}
