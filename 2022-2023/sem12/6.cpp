#include <type_traits>
#include <iostream>

template<typename T, std::enable_if<std::is_integral<T>::value, int>::type = 0>
void func(T value)
{
    std::cout << "int function" << std::endl;
    std::cout << __PRETTY_FUNCTION__<< std::endl;
}

template<typename T, std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
void func(T value)
{
    std::cout << "double function" << std::endl;
    std::cout << __PRETTY_FUNCTION__<< std::endl;
}

int main()
{
    func(100);
    func(1.4);
}
