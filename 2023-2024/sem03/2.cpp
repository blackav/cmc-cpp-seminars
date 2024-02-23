#include <iostream>
#include <format>
#include <string>

struct A
{
    int a{};
    std::string b;
    bool c = false;

    A(int a_, std::string b_, bool c_) : a(a_), b(b_), c(c_) {}
    A() : A(0, "", false) {}
    A(int a_);
    /*
    A(int a) = default;
*/
    //	A(const A&other) = default;
    A(const A &other) = delete;
};

/*
A::A(int a_) : A(a_, "" ,false)
{
}
*/
A::A(int a) { A::a = a; }

int
main()
{
    A a;
    A b{1, "x", true};
    A c{1};
    std::cout << std::format("{}\n", sizeof(A));
}
