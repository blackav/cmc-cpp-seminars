#include <iostream>
#include <iomanip>

int main()
{
  char c;

  std::cin >> std::noskipws;
  while (std::cin >> c) {
    std::cout << "(" << c << ")" << std::endl;
  }
}
