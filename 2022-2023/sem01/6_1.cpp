int func1(int a, int b)
{
    return a + b;
}

extern "C" int func2(int a, int b)
{
    return a + b;
}

#include <iostream>
using std::cin, std::cout, std::endl;

extern "C" int func3(int a, int b);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << func3(a, b) << endl;
}
