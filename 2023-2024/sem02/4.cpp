#include <iostream>

int
main()
{
    char *p = nullptr;
    nullptr_t x = nullptr;
    // auto x = nullptr;
    char *y = x;
    p = x;
    void *c{};
    c = p;
    // p = c; invalid
}
