#include <iostream>
#include <ranges>
#include <iterator>
#include <format>

int
main()
{
    int s{};
    for (auto x : std::views::istream<int>(std::cin)) {
        s += x;
    }
    std::format_to(std::ostream_iterator<char>(std::cout), "{}\n", s);
}
