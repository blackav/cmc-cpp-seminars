#include <utility>
#include <iostream>
#include <optional>

using std::pair, std::cout, std::endl;
using std::cin;

std::optional<int> f(int a)
{
    if (a > 0) return { a - 1 };
    return {};
}

int main()
{
    int x;
    while (cin >> x) {
        if (auto r = f(x); r) {
            cout << "result " << *r << endl;
        } else {
            cout << "error" << endl;
        }
    }
}
