#include <iostream>
#include <type_traits>

using namespace std;

template <int N>
struct F
{
    enum { V = F<N-1>::V * N };
};

template <>
struct F<0>
{
    enum { V = 1 };
};



template <typename T>
struct isinttype
{
    enum { value = false };
};
template <>
struct isinttype<int>
{
    enum { value = true };
};

template <typename T>
void fff()
{
}

int main()
{
    cout << F<10>::V << endl;

    cout << isinttype<char>::value << endl;
    cout << isinttype<int>::value << endl;

    char z;
    int a;
    cout << isinttype<decltype(z)>::value << endl;
    cout << isinttype<decltype(a)>::value << endl;
    cout << is_integral<decltype(z)>::value << endl;
}
