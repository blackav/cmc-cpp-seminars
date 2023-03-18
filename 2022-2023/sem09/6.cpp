#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> sp(new int{20});
    std::cout << *sp << std::endl;

    auto sp2 = std::make_shared<int>(100);
    std::cout << *sp2 << std::endl;
}
