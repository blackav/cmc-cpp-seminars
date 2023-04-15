#include <iostream>
#include <cstring>
#include <memory>

using std::cout, std::endl;
using std::unique_ptr, std::make_unique;

// в этом классе возможна утечка памяти, если при выделении памяти
// под ptr2 произойдет исключение. Память по указателю ptr1 утечет.
// Этот класс не предоставляет никаких гарантий обработки исключений.
struct A
{
    char *ptr1{};
    char *ptr2{};

    A(const char *p1, const char *p2) : ptr1(new char[strlen(p1) + 1]),
        ptr2(new char [strlen(p2) + 1])
        {
        }
    ~A()
    {
        delete[] ptr1;
        delete[] ptr2;
    }
};

// конструктор и списки инициализации можно обернуть в специальный
// try-блок уровня функции
struct B
{
    char *ptr1{};
    char *ptr2{};

    B(const char *p1, const char *p2) try : ptr1(new char[strlen(p1) + 1]),
        ptr2(new char [strlen(p2) + 1])
        {
        } catch (...) {
            delete[] ptr1;
            delete[] ptr2;
            // здесь исключение перевыбрасывается,
            // поэтому теряется информация об изначальной
            // причине исключения
            throw;
        }
    ~B()
    {
        delete[] ptr1;
        delete[] ptr2;
    }
};

// правильный способ - использование умных указателей
struct C
{
   unique_ptr<char[]> ptr1; 
   unique_ptr<char[]> ptr2;
    C(const char *p1, const char *p2)
    : ptr1(new char[strlen(p1) + 1]),
    ptr2(new char[strlen(p2) + 1])
    {
    }
};

// здесь невозможна утечка в случае,
// когда исключение возникает в процессе
// конструирования фактических параметров функции
void f(unique_ptr<A> a1, unique_ptr<B> b1)
{
}

int main() try
{
    f(make_unique<A>("", ""), make_unique<B>("", ""));
} catch (...)
{
}
