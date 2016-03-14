#include <iostream>

using namespace std;

class A 
{
public:
    virtual ~A() {}
    void f(int a) { cout << "A::f(int)\n"; }
    void f(double a) { cout << "A::f(double)\n"; }
    virtual void g(int a, int b = 10) { cout << "A::g(" << a << "," << b << ")\n"; }
    virtual void h() { cout << "A::h(double)" << endl; }
    virtual void k() ;
    void k()const {}
};

void A::k()
{
    cerr << "Ooops" << endl;
}

class B : public A
{
public:
    using A::f;
    void f(char a) { cout << "B::f(char)\n"; }
    void g(int a, int b = 20) { cout << "B::g(" << a << "," << b << ")\n"; }
    void h() { cout << "B::h()" << endl; }
    void k() { cout << "B::k()" << endl; }
};

int main()
{
    B b;
    A &a = b;
    B *c = &b;

    b.g(1);
    a.g(2);

    a.h();
    b.h();
    c->h();
    //c->h(1);
    //
    A *pa = new B;

    delete pa;
}
