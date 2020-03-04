#include <iostream>

using namespace std;

struct A
{
    A() = default;

    // оба конструктора ниже являются конструкторами копирования
    // но компилятор C++ может их различать, если объявлены оба
    // в реальных программах так делать не нужно, семантика переноса предпочтительнее
    A(const A &other) { cout << "A(const A&)" << endl; }
    A(A &other) { cout << "A(A&)" << endl; }
};

int main()
{
    A a;

    // здесь вызывается конструктор для аргумента-неконстантной ссылки A(A &)
    A b(a);

    const A c;

    // здесь вызывается конструктор для аргумента-константной ссылки A(const A&)
    A d(c);
}