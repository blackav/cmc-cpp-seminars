#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    vector<double> vd;

    //vector<int> v1{1, 2, 3, 4, 5};

    //v1.at(100000) = v1[4];

    vector<double> v1(4, -0.5);

    decltype(v1)::value_type x;
    while (cin >> x) {
        v1.push_back(x);
    }

    for (const auto &x : v1) {
        cout << x << endl;
    }
}
