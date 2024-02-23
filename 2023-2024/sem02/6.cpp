#include <iostream>
#include <string>

auto v1{0};
auto v2{1000L};
auto v3{'x'};
auto v4{"1234"};
auto v5{u8"1234"};

auto
func(int x) -> int
{
    return x + 1;
}

auto
func2(int y)
{
    return double(y);
}

auto
func3(auto x, auto y)
{
    return x + y;
}

auto
main() -> int
{
    const auto x = 10;
    auto y = x;
    decltype(x) z = x;
    std::cout << sizeof(v1) << std::endl;
    std::cout << sizeof(v2) << std::endl;
    std::cout << sizeof(v3) << std::endl;
    std::cout << sizeof(v4) << std::endl;
    std::cout << sizeof(v5) << std::endl;
    y++;

    std::string a{"A"}, b{"B"};
    std::cout << func3(a, b) << std::endl;
}
