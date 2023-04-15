#include <utility>
#include <iostream>
#include <array>

using std::pair, std::cout, std::endl;
using std::cin;

pair<int, bool> f(int a)
{
    if (a > 0) return { a - 1, true };
    return { 0, false };
}

int main()
{
    int x;
    /*
    while (cin >> x) {
        auto p = f(x);
        if (p.second) {
            cout << "result " << p.first << endl;
        } else {
            cout << "error" << endl;
        }
    }
    while (cin >> x) {
        if (auto p = f(x); p.second) {
            cout << "result " << p.first << endl;
        } else {
            cout << "error" << endl;
        }
    }
    */
    while (cin >> x) {
        if (auto [value, ok] = f(x); ok) {
            cout << "result " << value << endl;
        } else {
            cout << "error" << endl;
        }
    }

    std::array<int,2> a{1, 2};
    auto [v1, v2] = a;

    int b[] = {2, 3};
    auto [y1, y2] = b;
}
