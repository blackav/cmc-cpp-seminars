#include <iostream>

namespace A::B
{
  int myfunc(int a, int b);
}

int A::B::myfunc(int a, int b)
{
  return a + b;
}

int main()
{
  std::cout << A::B::myfunc(1, 2);
}
