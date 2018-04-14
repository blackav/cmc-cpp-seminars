#include <iostream>
#include <utility>

using namespace std;

/*
 шаблон с переменным числом параметров,
 для каждого параметра автоматически подберется
 наиболее подходящий вид ссылки
*/
template <typename ... TT>
void func(TT && ... args)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    func();
    func(1, 2, 4.6);

    int v1 = 1;
    const int v2 = 2;
    int &v3 = v1;
    const int &v4 = v2;

    func(1, v1, v2, v3, v4);
}
