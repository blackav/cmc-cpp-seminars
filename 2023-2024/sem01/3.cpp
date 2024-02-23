#include <format>
#include <iostream>
#include <iterator>

int
main()
{
    int a, b;
    std::cin >> a >> b;

    std::cout << std::format("{}", a + b) << std::endl;

    std::ostream_iterator oi = std::ostream_iterator<char>(std::cout);
    std::format_to(oi, "{}\n", a + b);

    std::print("{}\n", a + b);
}
