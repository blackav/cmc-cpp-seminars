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

struct C
{
};

void f(A *p)
{
    if (typeid(*p) == typeid(A)) {
        cout << "A" << endl;
    } else if (typeid(*p) == typeid(B)) {
        cout << "B" << endl;
    }
}

int main()
{
    A *pa = new B;

    const type_info &ti = typeid(*pa);
    cout << ti.name() << endl;
    f(pa);
    f(new A);
    try {
        f(nullptr);
    } catch (...) {
    }
}
