template<typename T>
struct is_int
{
    static constexpr auto value = false;
};

template<>
struct is_int<int>
{
    static constexpr auto value = true;
};

#include <iostream>

using namespace std;

int main()
{
    cout << is_int<double>::value << endl;
    cout << is_int<int>::value << endl;

    int x = 10;
    static_assert(is_int<decltype(x)>::value);
    if constexpr(is_int<decltype(x)>::value) {
        cout << x << endl;
    }
}
