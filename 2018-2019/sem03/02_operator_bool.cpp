#include <iostream>

struct A
{
    explicit operator bool () const
    {
        std::cout << "operator bool" << std::endl;
    }
/*
    operator void *() const
    {
        std::cout << "operator void *" << std::endl;
    }
*/
};

int main()
{
    A a;

    //int z = a;
    //const char *s = a;

    while (a) {
    }
}
