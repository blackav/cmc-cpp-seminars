#include <iostream>
#include <algorithm>

using std::cout, std::endl;

struct Oper
{
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

int main()
{
    Oper o;

    o(10, 20);
    std::cout << o(11, 12) << endl;

    int a[]{ 5, 4, 2, 1, 0 };
    std::sort(a, a + 5, Oper());
    for (auto v : a) {
        cout << v << endl;
    }
}
