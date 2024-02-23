#include <iostream>

extern "C" int func(int x);

extern "C" int
func2(int x)
{
    return x + 2;
}

int
func3(int x)
{
    return x + 4;
}

int
main()
{
    int x;
    std::cin >> x;
    std::cout << func(x) << std::endl;
}
