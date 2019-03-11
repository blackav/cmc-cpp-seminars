#include <iostream>

template<typename T>
auto sum(const T &v, typename T::value_type s = {})
{
    for (const auto &x : v) {
        s += x;
    }
    return s;
}

template<typename T, typename F>
auto accum(const T &v, F f, typename T::value_type s = {})
{
    for (const auto &x : v) {
        f(s, x);
    }
    return s;
}

#include <vector>
#include <list>
#include <set>
#include <functional>

using namespace std;

void func(int &s, int x)
{
    s += x;
}

template<typename T>
void func2(T &s, T x)
{
    s += x;
}

struct Z
{
    void operator()(int &s, int x) const { s += x; }
};

template<typename T>
struct Y
{
    void operator()(T &s, T x) const { s += x; }
};

int main()
{
    vector v1{1, 2, 3, 4, 5, 6, 7};

    cout << sum(v1, 199) << endl;

    list v2{1.4, 3.5};
    cout << sum(v2) << endl;

    set v3{string("a"), string("b")};
    cout << sum(v3) << endl;

    cout << accum(v1, func, 10) << endl;
    cout << accum(v1, func2<int>, 10) << endl;
    cout << accum(v1, Z{}, 10) << endl;
    cout << accum(v1, Y<int>(), 10) << endl;
    cout << accum(v1, [](int &s, int x) { s += x; }, 22) << endl;
    cout << accum(v1, [](auto &s, auto x) { s += x; }, 22) << endl;
    cout << accum(v1, std::function<void (int &, int)>(func), 44) << endl;
}
