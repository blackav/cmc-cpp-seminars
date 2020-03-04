/* -*- mode: c++; c-basic-offset: 4 -*- */

#include <iostream>

/*
в этом примере рассматривается
1) глобальное нетипизированное выделение памяти ::operator new
2) глобальное нетипизированное освобождение памяти ::operator delete
3) placement new (явный вызов конструктора для инициализации объекта на предварительно выделенной памяти)
4) явный вызов деструктора (только в случае использования placement new)
 */
struct A
{
    A()
    {
        std::cout << "A()" << std::endl;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

int main()
{
    A *pa = new A;

    delete pa;

    void *pv = ::operator new(sizeof(A));
    A *pb = new (pv) A;

    pb->~A();
    ::operator delete(pb);
}
