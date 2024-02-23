#include <format>
#include <iostream>

namespace A
{
int a;
void f();
using T1 = int;
} // namespace A

namespace A
{
double b;

namespace B
{
float c;
}
} // namespace A

namespace A::B
{
void g(int _);
extern long x;
} // namespace A::B

namespace
{
double d;
}

void
A::B::g(int x)
{
}

long A::B::x;

namespace A
{
void
f()
{
}
} // namespace A

char x;

int
main()
{
    using A::B::x;

    std::cout << std::format("{}\n", sizeof(x));

    {
        using ::x;
        std::cout << std::format("{}\n", sizeof(x));
    }

    {
        static int x;
        std::cout << std::format("{}\n", sizeof(x));
    }
}
