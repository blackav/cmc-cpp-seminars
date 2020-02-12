#include <iostream>

auto func(auto a, auto b)
{
  return a + b;
}

int main()
{
  auto a = 0;
  auto b = a;

  std::cin >> a >> b;
  std::cout << func(a, b) << std::endl;
}
