#include <iostream>
#include <utility>

using namespace std;

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

/*
 perfect forwarding - подбирается наиболее подходящий вид ссылки
 и она передается без преобразования в значение в функцию func
 с помощью std::forward<T>
*/
template<typename T>
void forw(T &&a)
{
    func(forward<T>(a));
}

int main()
{
    int v1 = 10;
    const int v2 = 20;

    int &v3 = v1;
    const int &v4 = v1;

    forw(1);
    forw(v1);
    forw(v2);
    forw(v3);
    forw(v4);
}
