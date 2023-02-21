#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

struct A
{
    int a{};
    A(int aa = 0) : a(aa) {}

    A operator+(A a2) const
    {
        return A(a + a2.a);
    }
};

A operator*(A a1, A a2)
{
    return A(a1.a * a2.a);
}

int main()
{
    A a1{1}, a2{10}, a3{100};

    auto a4 = a1.operator+(a2);
    cout << a4.a << endl;

    auto a5 = a2 + a3;
    cout << a5.a << endl;

    cout << (a1 + a3).a << endl;
    cout << a1.operator+(a2).a << endl;

    auto a6 = operator*(a1, a2);
    cout << a6.a << endl;

    cout << operator*(a1, a2).a << endl;

    auto a7 = a6 + 100;
    cout << a7.a << endl;

    auto a8 = A(100) + a6;
    auto a9 = 100 * a6;
    cout << a9.a << endl;
}
