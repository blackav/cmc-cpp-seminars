#include <iostream>
#include <algorithm>

using std::cout, std::endl;

auto f()
{
    int x = 100;
    return [&x]() { cout << x++ << endl; };
}

int main()
{
    f()();
    f()();
}
