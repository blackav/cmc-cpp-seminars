#include <iostream>

template<typename T>
auto sum(T beg, T end, typename T::value_type s = {})
{
    for (; beg != end; ++beg) {
        s += *beg;
    }
    return s;
}
template<typename T>
auto sum(T *beg, T *end, T s = {})
{
    for (; beg != end; ++beg) {
        s += *beg;
    }
    return s;
}

#include <vector>
#include <list>
#include <set>
#include <functional>

using namespace std;

int main()
{
    vector v1{1, 2, 3, 4, 5, 6, 7};

    cout << sum(v1.begin() + 1, v1.end() - 1, 199) << endl;

    list v2{1.4, 3.5};
    cout << sum(v2.begin(), v2.end()) << endl;

    set v3{string("a"), string("b")};
    cout << sum(v3.begin(), v3.end()) << endl;

    double v4[]{1, 2, 3, 4, 5, 6, 7};
    cout << sum(v4, v4 + 5, 0.5) << endl;
}
