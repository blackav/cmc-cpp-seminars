#include <iostream>
#include <format>
#include <string>

struct A
{
    int a_{};
    std::string b_;
    bool c_ = false;

    int
    a() const noexcept
    {
        return a_;
    }
    void
    set_a(int a) noexcept
    {
        a_ = a;
    }

    A(int a, std::string b, bool c) : a_(a), b_(b), c_(c) {}
    A() : A(0, "", false) {}
    explicit A(int a);
    A(const A &other) = default;
};

A::A(int a) : A(a, "", false) {}

void
f(A a) noexcept
{
    std::cout << std::format("{}:{}\n", __PRETTY_FUNCTION__, a.a());
}

int
main()
{
    A a;
    A b{1, "x", true};
    A c{0x100};
    std::cout << std::format("{}\n", sizeof(A));
    const A d{100500, "y", false};

    std::cout << std::format("{:x}\n", c.a());
    std::cout << std::format("{:x}\n", d.a());
    f(c);
    f(d);
    f(100);
    f(100.0);
    f({101});
    // f({101.0});
    f(A{101});
}
