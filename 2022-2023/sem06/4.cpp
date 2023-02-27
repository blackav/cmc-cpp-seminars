#include <iostream>
#include <algorithm>

using std::cout, std::endl;

int main()
{
    int a[]{ 5, 4, 2, 1, 0 };
    std::sort(a, a + 5, [](int a, int b) -> bool { return a < b; });
    for (auto v : a) {
        cout << v << endl;
    }

    cout << [](auto a) { cout << a + 1 << endl; return a - 1; }(a[0]) << endl;

    auto f = [] { cout << "hehe" << endl; };
    f();

    int b = 100;

    auto f1 = [a=a[0], b]() { cout << a << " " << b << endl; };
    f1();
    cout << a[0] << endl;

    auto f2 = [&b]() { cout << b++ << endl; };
    f2();
    cout << b << endl;

    auto f3 = [=]() { cout << b << endl; };
    auto f4 = [&]() { cout << b++ << endl; };

    f3();
    f4();
}
