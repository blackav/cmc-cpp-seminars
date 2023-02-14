#include <iostream>

namespace A
{
    int b;
    double c;
    namespace B
    {
        long d;
    }
}

namespace A::B
{
    char e;
}

namespace
{
    long g;
}

long long f;

int main()
{
    using std::cout, std::endl;

    cout << ::g << endl;
    cout << ::f << endl;
    cout << A::B::e << endl;
    using A::B::e;
    cout << e << endl;
}
