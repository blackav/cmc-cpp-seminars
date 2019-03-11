#include <iostream>

using namespace std;

template<typename C>
void myswap(C &a, C &b)
{
    // rvalue reference для оптимизации копирований
    auto tmp{move(a)};
    a = move(b);
    b = move(tmp);
}

template<class C>
void myswap(C *a, C *b)
{
    auto tmp{*a};
    *a = *b;
    *b = tmp;
}

template<>
void myswap(int &a, int &b)
{
    cout << "int" << endl;
}


int main()
{

    int a = 10, b = 20;

    myswap<int>(a, b);
    cout << a << " " << b << endl;
    myswap<int>(a, b);

    myswap(a, b);

    double c = 1.1, d = 2.2;
    myswap(c, d);

    double *pc = &c, *pd = &d;
    cout << (void *) pc << " " << (void*) pd << endl;
    myswap(pc, pd);
    cout << (void *) pc << " " << (void*) pd << endl;
    cout << *pc << " " << *pd << endl;
}
