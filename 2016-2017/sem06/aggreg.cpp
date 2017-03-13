#include <iostream>

using namespace std;

struct A
{
    int a;
    double b;
};

struct B
{
    struct A _a;
    int c;
};

struct C : public A
{
    int c;
};

int main()
{
    C c;
    B b;
    (void) b;

    A *pa = &c;

    cout << (void*) &c << endl;
    cout << (void*) pa << endl;
    //cout << offsetof(b.c) << endl;
}
