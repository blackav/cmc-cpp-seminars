#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <string>

using namespace std;

template<typename T>
auto summ(const T &v1)
{
    //decltype(*v1.begin()) res = 0;
    typename T::value_type res{};
    for (auto ii = v1.begin(); ii != v1.end(); ++ii) {
        res += *ii;
    }
    return res;
}

int main()
{
    vector v1{4, 5, 6, 7};
    cout << summ(v1) << endl;

    list l1{34, 44};
    set us{33, 44, 55};
    cout << summ(l1) << endl;
    cout << summ(us) << endl;

    vector v2{1.2, 0.5};
    cout << summ(v2) << endl;

    vector v3{string("a"), string("b"), string("c")};
    cout << summ(v3) << endl;
}
