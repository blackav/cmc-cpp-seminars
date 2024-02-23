#include <iostream>
#include <iomanip>

int
main()
{
    int a, b;
    std::cin >> a >> b;
    // std::cin.operator>>(a);
    std::cout << a + b << std::endl;
    std::cout << std::setw(14) << std::hex << a + b << std::endl;
}
