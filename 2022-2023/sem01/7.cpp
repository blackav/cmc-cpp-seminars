#include <iostream>

auto a = 100;
auto b = 'v';
auto c = "vv";

auto func(int a)
{
    return a + 1;
}

auto func2(int a) -> double
{
    return a + 1;
}

auto func3(auto a)
{
    return a + 1;
}

using std::cout;
using std::endl;
int main(int argc, char **argv)
{
    [[maybe_unused]]
    auto d = a;

    auto e{nullptr};

    int *p = e;
    cout << p << endl;
}
