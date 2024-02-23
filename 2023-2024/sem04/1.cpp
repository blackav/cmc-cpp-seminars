#include <iostream>
#include <string>

struct A
{
    int a_{};

    A() = default;
    A(int a) noexcept : a_(a) {}
    A(std::string s)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        a_ = std::stoi(s);
    }

    /*
            operator double() const noexcept
            {
                    std::cout << __PRETTY_FUNCTION__ << std::endl;
                    return a_ + 0.5;
            }
    */
    explicit operator std::string() const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return std::to_string(a_);
    }
    explicit operator bool() const noexcept { return bool(a_); }
};

void
f(A a)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int
main()
{
    A a;
    f(1);
    f(1.5);
    f(std::string("1212"));
    // f("123123");

    // double y = 1.5 + a;
    // auto z = operator+(1.5, a);
    // auto t = 1 + a;
    // std::cout << sizeof(t) << std::endl;
    auto b = !a;
    bool b2 = bool(a);
    bool b3 = 1 && a;
    if (a) {
    }

    // auto t2 = std::string("aaa") + a;
    // auto ss = std::string(a);
    // auto t3 = operator+(std::string("aaa"),a);
}
