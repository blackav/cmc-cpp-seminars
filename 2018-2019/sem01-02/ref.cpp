#include <stdio.h>

void func(const int &z)
{
    printf("%d\n", z);
}

/*
void func(int z)
{
}
*/

void swap(int &a, int &b)
{
    int x = a;
    a = b;
    b = x;
}

int main()
{
    int a = 10;
    int &b = a;

    b = 11;
    ++b;

    int &c{b};

    int y = 60;
    swap(c, y);

    char z = 'x';
    //swap(c, (int) z);
    func((int) z);
    func(c);

}
