#include <iostream>

using namespace std;

/*
 запись && в параметре шаблона, подразумевающем вывод типа,
 обозначает, что может выводиться любая из трех видов ссылки,
 наиболее подходящая по контексту использования
*/
template <typename T>
void func(T &&a)
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
