#include <iostream>

using namespace std;

/*
// передача параметра по значению конфликтует с передачей по ссылке
// во многих контекстах
void func(int a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}
*/

/*
 три типа ссылок полностью покрывают все возможности использования
 значений и переменных в Си++, они не конфликтуют друг с другом
 lvalue reference - &
 const lvalue reference - const &
 rvalue reference - &&
*/

void func(int &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void func(const int &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void func(int &&a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}


int main()
{
    int v1 = 10;
    const int v2 = 20;

    int &v3 = v1;
    const int &v4 = v1;

    func(1);
    func(v1);
    func(v2);
    func(v3);
    func(v4);
}
