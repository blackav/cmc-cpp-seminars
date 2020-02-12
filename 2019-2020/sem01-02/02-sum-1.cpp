#include <iostream>
#include <iomanip>

#include <cstdint>

int main()
{
  //int64_t sum = 0;
  //int64_t sum(0);
  //int64_t sum{0};
  //int64_t sum{};
  //int64_t sum = int64_t();
  //  int64_t sum(); -- NEVER!!!

  int64_t sum{};

  //bool z = bool(std::cin);
  //  bool z = true && std::cin;
  //[[maybe_unused]]
    //bool z = static_cast<bool>(std::cin);
    //bool z = (bool) std::cin;

  int a;
  while (std::cin >> a) {
    sum += a;
  }
  /*
  while (!(std::cin>>a).eof()) {
    sum += a;
  }
  */
  /*
  while (1) {
    int a;

    std::cin >> a;
    if (std::cin.eof()) {
      break;
    }
    sum += a;
  }
  */
  std::cout << std::hex << std::setw(10) << std::setfill('0') << sum << " " << std::dec << sum << std::endl;
  //printf("%010lx %ld\n", sum, sum);
}
