#include <iostream>
#include <format>
#include <string>
#include <cstdint>

// using T = long long;
// using T = std::string;
// using T = int;
using T = int64_t;

int
main()
{
    // T a, b;
    T a = T();
    // T b = T();
    //  T b = 0;
    // T b(0);
    //  T b(); <-- declaration
    // T b = {100'000'000'000'000};
    // T b{};
    // T b{1e9+7};
    // T b{int(100'000'000'000'000)};
    T b{100};

    [[maybe_unused]] T c{};

    std::cout << std::format("{:05}", a + b) << std::endl;
}
