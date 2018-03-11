#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(32);
    vector<int> v3(32, -5);
    vector<int> v4(v3);
    vector<int> v5{1, 2, 3, 4, 5};

    cout << v5[1] << endl;
    //cout << v5.at(-2) << endl;

    vector<int>::iterator i1;
    vector<int>::const_iterator i2;

    vector<int>::reverse_iterator i3;
    vector<int>::const_reverse_iterator i4;

    auto ia = v5.begin(); // end()
    auto ib = v5.cbegin(); // cend()
    auto ic = v5.rbegin(); // rend()
    auto id = v5.crbegin(); // crend()

    for (auto iz = v5.begin(); iz != v5.end(); ++iz) {
        auto x = *iz;
        cout << x << endl;
    }

    // range-based for
    for (const auto &x : v5) {
        cout << x << endl;
    }


    vector<int> v6(v5.begin() + 1, v5.end() - 1);
    for (const auto &x : v6) {
        cout << x << endl;
    }



    vector<double> v7;
    v7.resize(2, 3.0);
    v7.resize(4, 5.0);
    for (const auto &x : v7) {
        cout << x << endl;
    }

    v7.reserve(1024);
    cout << v7.size() << endl;
}
