#include <iostream>
#include <memory>
#include <utility>

using namespace std;

/*
Шаблонный класс MyTuple с переменным числом полей.
Реализация с помощью частичной специализации и наследования.
 */

template <typename ... A>
struct MyTuple
{
    //A &&...f;
    MyTuple(A &&...a)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

template<typename T1, typename ... T2>
struct MyTuple<T1, T2...> : public MyTuple<T2...>
{
    T1 f;
    MyTuple(T1 && t1, T2 && ... t2)
        : MyTuple<T2...>(forward<T2>(t2)...), f(forward<T1>(t1))
    {
    }
};

template<>
struct MyTuple<>
{
    MyTuple()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    int z = 0;
    MyTuple<int, double, int &> t1(1, 2.0, z);
    MyTuple<> t2;


}
