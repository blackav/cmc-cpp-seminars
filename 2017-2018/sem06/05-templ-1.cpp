#include <iostream>

using namespace std;

template<class T, int a = 10>
void
myswap(T &v1, T &v2)
{
    static_assert(sizeof(T) == 8);
    T v3 = v1;
    v1 = v2;
    v2 = v3;
}

int main()
{
    double v1 = 1, v2 = 2;
    myswap<double>(v1, v2);
    myswap(v2, v1);

    long long a, b;
    myswap(a, b);
}
