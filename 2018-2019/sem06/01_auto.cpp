#include <iostream>

using namespace std;

auto f(int s)
{
    cout << s << endl;
    return double(s);
}

auto g(int s) -> double
{
    cout << s << endl;
    return s;
}

auto h(auto a, auto b)
{
    return a + b;
}

int main()
{
    auto x = 10;
    cout << f(x) << endl;
    cout << g(20) << endl;
    cout << h(100, 200) << endl;
}
