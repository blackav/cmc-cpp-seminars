#include <iostream>

using namespace std;

/*
совместное использование передачи по ссылке и по значению в
перегружаемых аргументах почти всегда приводит к неоднозначности.
вместо передачи параметра по значению нужно использовать передачу
параметра по rvalue reference
 */

void f(int &&a)
{
    cout << "f(int&&)" << endl;
}

void f(int &a)
{
    cout << "f(int&)" << endl;
}

void f(const int &a)
{
    cout << "f(const int&)" << endl;
}

int main()
{
    int a = 0;
    const int b = 0;

    f(1); // f(int&&)
    f(a); // f(int&)
    f(b); // f(const int&)
}
