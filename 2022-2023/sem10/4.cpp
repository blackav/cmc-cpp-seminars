#include <iostream>
#include <utility>

using std::cin, std::cout, std::endl;

void g(int &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(const int &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(int &&a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T>
void f(T &&t)
{
    cout << __PRETTY_FUNCTION__ << endl;
    g(std::forward<T>(t));
}

int main()
{
    int a = 10;
    int &ra = a;
    const int b = 20;
    const int &crb = b;
    int c = 20;

    f(ra);
    f(crb);
    f(std::move(c));
}
