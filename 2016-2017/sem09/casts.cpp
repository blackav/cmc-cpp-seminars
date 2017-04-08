#include <iostream>

struct A
{
};

struct B : A
{
};

struct C
{
};

int main()
{
    // static_cast<T>(e)
    // const_cast<T>(e)
    // reinterpret_cast<T>(e)

    void *p = malloc(100);
    int *a = reinterpret_cast<int*>(p);    
    int *b = static_cast<int*>(p);    

    A *pa = new A;
    B *pb = static_cast<B*>(pa);

    C *pc = reinterpret_cast<C*>(pa);
    double *c = reinterpret_cast<double*>(b);

    int aaa = reinterpret_cast<int>(pc);

    char *str1 = new char[1000];
    unsigned char *str2 = reinterpret_cast<unsigned char*>(str1);

    const char *str3 = str1;
    char *str4 = const_cast<char*>(str3);
}
