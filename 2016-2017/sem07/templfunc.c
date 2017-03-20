#include <iostream>

using namespace std;

template <typename T>
void myswap(T &v1, T &v2)
{
    T tmp{v1};
    v1 = v2;
    v2 = tmp;
}

template <>
void myswap(int &v1, int &v2)
{
    int tmp{v1};
    v1 = v2;
    v2 = tmp;
    cout << "int!" << endl;
}

template <typename T, typename T2 = int, int N = 10>
void myfunc(T v1, const T2 &v2 = T2{})
{
    cout << v1 << " " << v2 << " " << N << endl;
}

struct A
{
    int v = 0;
    A(int v) : v(v) {}
    //A(const A&) = delete;
    //A& operator =(const A&) = delete;
};

int main()
{
    myfunc<int, double, 20>(50, 10);
    myfunc<int, double>(100, 200);
    myfunc<int, double>(400);
    myfunc(700);
    myfunc(1000, 'a');


    int i1 = 10, i2 = 20;

    myswap<int>(i1, i2);
    cout << i1 << " " << i2 << endl;

    int i3 = 40, i4 = 50;
    myswap<int>(i3, i4);

    myswap(i1, i4);
    cout << i1 <<  " " << i4 << endl;

    double d1 = 1.5, d2 = 1.6;
    myswap(d1, d2);
    cout << d1 <<  " " << d2 << endl;

    A a1{145}, a2{555};
    myswap(a1, a2);
    cout << a1.v << " " << a2.v << endl;

    //myswap(a1, i1);
    double *pd1 = new double{1.1}, *pd2 = new double{2.2};
    int *pi1 = new int{100}, *pi2 = new int{200};
    myswap(pd1, pd2);
    myswap(pi1, pi2);
    cout << *pd1 << " " << *pd2 << endl;
    cout << *pi1 << " " << *pi2 << endl;
}
