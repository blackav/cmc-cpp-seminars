#include <iostream>

//#include <stdint.h>
#include <cstdint>

int main(int argc, char **argv)
{
  int32_t a, b;

  //(std::cin >> a) >> b;
  std::cin.operator>>(a).operator>>(b);

  //((std::cout << a) << " " << b) << std::endl;
  std::cout.operator<<(a).operator<<(b).operator<<(std::endl);
}
