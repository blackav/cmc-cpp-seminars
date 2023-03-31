#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::cout, std::endl, std::vector, std::list;

template<typename It>
auto sum(It beg, It end)
{
    typename std::iterator_traits<It>::value_type s{};
    for (; beg != end; ++beg)
        s += *beg;

    return s;
}

int main()
{
    vector v1{1, 2, 3, 4};
    list l1{100, 200};

    cout << sum(v1.begin() + 1, v1.end()) << endl;
    cout << sum(l1.begin(), l1.end()) << endl;

    int a1[]{1001, 1002, 1003, 1004};

    cout << sum(a1, a1 + 4) << endl;
}
