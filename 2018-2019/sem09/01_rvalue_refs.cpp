#include <iostream>

using namespace std;

int main()
{
    int a{};

    int &ra = a;
    ++ra;

    cout << ra << endl;

    const int &cra = a;
    cout << cra << endl;

    // rvalue-reference - получаем ссылку на временный объект
    // время жизни временного объекта будет продлено до конца блока
    int &&rra = a + 1;

    const int &cc = a + 1;

    ++rra;
    cout << rra << endl;

    // "заставляем" компилятор считать переменную "a" временной,
    // на которую можно получить rvalue-reference
    int &&rra2 = move(a);
}
