#include <iostream>
#include <vector>

using namespace std;

int mysum(const vector<int> &v)
{
    int s = 0;
    for (const auto &x : v)
        s += x;
    return s;
}

/*
template<typename T>
typename T::value_type mysum2(const T &v)
{
    typename T::value_type s{};
    for (const auto &x : v)
        s += x;
    return s;
}
*/

template<typename T>
auto mysum2(const T &v)
{
    auto s = decltype(v[0]){};
    for (const auto &x : v)
        s += x;
    return s;
}

template<typename T>
auto mysum3(T i1, T i2)
{
    typename T::value_type s{};
    //auto s = decltype(*i1){};
    for (; i1 != i2; ++i1)
        s += *i1;
    return s;
}

int main()
{
    vector<int> v1{1, 2, 6, 8, 100};

    vector<int>::value_type z = 5;

    cout << mysum(v1) << endl;

    //cout << mysum2<int, vector<int>>(v1) << endl;

    cout << mysum2(v1) << endl;

    double ad[] = { 1.1, 2.2, 3.3 };
    cout << mysum2(ad) << endl;
    double ad2[] = { 1.1, 2.2, 3.3, 4.4 };
    cout << mysum2(ad2) << endl;

    cout << mysum3(v1.begin(), v1.end() - 1) << endl;
}
