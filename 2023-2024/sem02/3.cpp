#include <iostream>
#include <format>
#include <string>

const int AA = 100;

void
f(const int x)
{
}

void
g(const char *c)
{
}

constexpr int BB = 6;

int bb[BB];

constexpr int
fact(int x)
{
    std::string y{"aaaa"};
    return x <= 0 ? int(y.size()) : fact(x - 1) * x;
}

char cc[fact(BB)];

int
main()
{
    std::cout << std::format("{}\n", sizeof(cc));
    int x;
    std::cin >> x;
    std::cout << std::format("{}\n", fact(x));
}
