#include <iostream>

using namespace std;

auto func(int (*a)(int), auto b) -> auto
{
    return a(b);
}

int main()
{
    int z;
    cin >> z;
    cout << func([](auto x) -> auto { return x + 3333; }, 10) << endl;
}
