#include <memory>
#include <iostream>

using namespace std;

struct A
{
    int f = 0;

    A()
    {
        cout << "A()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
};

int main()
{
    void *ptr = ::operator new(sizeof(A));
    A *p2 = new (ptr) A;

    A *p = new A;

    p2->~A();

    new (ptr) A;
    p2->~A();

    ::operator delete(ptr, sizeof(A));
    // p->~A(); UB!!!!
    delete p;
}
