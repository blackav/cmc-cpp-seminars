#include <iostream>
#include <utility>
#include <memory>

using namespace std;

void func()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void func(int a, int &b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void func(int a, const int &b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void func(int a, double b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

/*
 perfect forwarding в шаблоне с переменным числом аргументов
 для всех аргументов подбирается наиболее подходящий вид ссылки
 и передается без преобразования значений в функцию func
*/
template <typename ... TT>
void forw(TT && ... args)
{
    cout << __PRETTY_FUNCTION__ << endl;
    func(forward<TT>(args)...);
}

/*
 вызов конструктора класса C и forwarding в конструктор
 всех последующих параметров шаблона
*/
template <typename C, typename ... TT>
auto my_make_unique(TT && ... args)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return unique_ptr<C>(new C(forward<TT>(args)...));
}

struct C
{
C()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

C(int a, int &b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

C(int a, const int &b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}
};

int main()
{
    int a = 10;
    forw();
    forw(10, a);
    forw(10, 20);
    forw(10, 2.5);

    supernew<C>();
    supernew<C>(10, a);
    supernew<C>(10, 20);
}
