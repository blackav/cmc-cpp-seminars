#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

// шаблонная функция swap, которая меняет местами аргументы без лишнего копирования
template<typename T>
void myswap(T &v1, T &v2)
{
    T v3 = std::move(v1);
    v1 = std::move(v2);
    v2 = std::move(v3);
}

// простейший вариант поиска по контейнерному классу
template<typename IT>
IT myfind(IT ib, IT ie, typename IT::value_type v)
{
    for (; ib != ie; ++ib)
        if (*ib == v)
            return ib;
    return ie;
}

// вспомогательный класс-функтор для использования в mysum, использует operator+ для операции над значениями
template<typename T>
struct mysumclass
{
    T operator()(const T &v1, const T &v2) { return v1 + v2; }
};

template<typename IT,
         typename S = mysumclass<typename IT::value_type> // аргумент шаблона по умолчанию - функтор сложения аргументов
         >
typename IT::value_type mysum(IT ib, IT ie,
                              typename IT::value_type sum = typename IT::value_type(), // начальное значение, по умолчанию - значение по умолч.
                              S s = S()) // операция свертки
{
    for (; ib != ie; ++ib)
        sum = s(sum, *ib);
    return sum;
}

int sss(int a, int b)
{
    return a + b + 1;
}

int main()
{
    list<int> l1;
    list<int> l2{1, 2, 3, 4};

    auto ie = l2.rend();
    for (auto ib = l2.rbegin(); ib != ie; ++ib) {
        l2.insert(l2.begin(), *ib);
    }

    for (auto z : l2) {
        cout << z << endl;
    }

    auto ii = myfind(l2.begin(), l2.end(), 3);
    if (ii != l2.end()) {
        cout << *ii << endl;
    }

    int i1 = 10, i2 = 20;
    //myswap<int>(i1, i2);
    myswap(i1, i2);

    cout << i1 << "," << i2 << endl;

    cout << mysum(l2.begin(), l2.end()) << endl;
    cout << mysum(l2.begin(), l2.end(), 0, [](int a, int b) -> auto { return a + b; }) << endl;;

    cout << mysum(l2.begin(), l2.end(), 1, [](int a, int b) -> auto { return a * b; }) << endl;;
    cout << mysum(l2.begin(), l2.end(), 0, sss) << endl;
}
