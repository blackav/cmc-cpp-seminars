#include <iostream>

using namespace std;

/*
 пример демонстрирует "двойственность" указателей в Си++
 с одной стороны, указатель T* может быть началом массива T[]
 с другой стороны, указатель T* может указывать на
 объект любого производного класса

 Это может приводить к ошибкам!
*/

struct A
{
    int fa = 0;

    virtual ~A()
    {
        cout << "~A()" << endl;
    }
};

struct B : public A
{
    int fb = 0;

    ~B()
    {
        cout << "~B()" << endl;
    }
};

int main()
{
    A *p1 = new A[4];
    delete[] p1;

    cout << endl;

    B *p2 = new B[4];
    delete[] p2;

    cout << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    A *p3 = new B[4];
    delete[] p3;

}

