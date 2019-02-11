#include <stdio.h>

void f()
{
    printf("f()\n");
}

void f(char c)
{
    printf("f(char)\n");
}

void f(int z)
{
    printf("f(int)\n");
}

void f(unsigned char c)
{
    printf("f(unsigned char)\n");
}

void f(double d)
{
    printf("f(double)\n");
}

void f(const long &l)
{
    printf("f(const long&)\n");
}

void f(long &rl)
{
    printf("f(long &)\n");
}

void f(const char *s)
{
    printf("f(const char *)\n");
}
void f(char *s)
{
    printf("f(char *)\n");
}

int main()
{
    f();

    int z{};
    f(z);

    double d{};
    f(d);

    // promotion
    char c;
    f(c);

    long l;
    f(l);

    unsigned long ul;
    f(long(ul));

    f((signed char) ul);

    f('z');

    f("asds");

    char *s;
    f(s);

    //f(nullptr);
}
