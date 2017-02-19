#include <iostream>

using namespace std;

struct A
{
};

struct B : A
{
    void f() { cout << "B::f()" << endl; }
};

struct C
{
    void f() { cout << "C::f()" << endl; }
};

int main()
{
    const int *p = new int{10};

    //(*p)++;

    (*(int *) p)++;
    (*const_cast<int*>(p))++; // const_cast<T>(v)

    //double b = const_cast<decltype(b)>(*p);

    cout << *p << endl;

    A *pa = new B;

    static_cast<B*>(pa)->f();
    //static_cast<C*>(pa)->f();

    const char *pc = "abcd";
    //const unsigned char *up = static_cast<const unsigned char*>(pc);
    ((C*) pa)->f();
    //
    reinterpret_cast<C*>(pa)->f();
}
