
// использование ключевого слова 'const' дает константу периода компиляции (в Си - нет!)
const int M = 10;

int m[M] = {};

// 'constexpr' - замена 'const' в C++11
// 'auto' - автовывод типа из типа инициализатора
constexpr auto const1 = 0;    // int
constexpr auto const2 = 'z';  // char
constexpr auto const3 = 5.6;  // double

int a1[const2];
int a2[(int) const3];  // нужно приведение типа - размер должен быть целочисленным типом

// функции, которые можно вычислить при компиляции программы
constexpr int f2(int z) { int a = z; return a * z; }
constexpr int func(int z) { return const2 - 'a'; }

// обычная глобальная переменная
auto x = 10; // int

// размер массива вычисляется при компиляции
int a3[f2(func(10))];

#include <iostream>

using namespace std;

int main()
{
    cout << sizeof(a3) / sizeof(a3[0]) << endl;
}
