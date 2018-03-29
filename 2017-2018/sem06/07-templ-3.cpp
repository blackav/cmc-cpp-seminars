#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <string>

using namespace std;

template <typename T>
struct sum2
{
    T operator()(T v1, T v2) const { return v1 + v2; }
};

template<typename T, typename F = sum2<typename T::value_type> >
auto summ(T i1, T i2, F f = F{})
{
    //decltype(*v1.begin()) res = 0;
    typename T::value_type res{};
    for (auto ii = i1; ii != i2; ++ii) {
        //res += *ii;
        res = f(res, *ii);
    }
    return res;
}

int main()
{
    vector v1{4, 5, 6, 7};
    cout << summ(v1.begin(), v1.end()) << endl;

    list l1{34, 44};
    set us{33, 44, 55};
    cout << summ(l1.begin(), l1.end()) << endl;
    cout << summ(us.crbegin(), us.crend()) << endl;

    vector v2{1.2, 0.5};
    cout << summ(v2.cbegin(), v2.cend()) << endl;

    vector v3{string("a"), string("b"), string("c")};
    cout << summ(v3.rbegin(), v3.rend()) << endl;

    cout << summ(v2.begin(), v2.end(), [](auto a, auto b) { return a * b; });
}
