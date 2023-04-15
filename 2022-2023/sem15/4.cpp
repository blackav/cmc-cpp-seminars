#include <utility>
#include <iostream>
#include <optional>
#include <expected>

using std::pair, std::cout, std::endl;
using std::cin;

std::expected<int, const char *> f(int a)
{
    if (a > 0) return { a - 1 };
    return std::unexpected("fail");
}

int main()
{
    int x;
    while (cin >> x) {
        if (auto r = f(x); r) {
            cout << "result " << *r << endl;
        } else {
            cout << "error: " << r.error() << endl;
        }
    }
}
