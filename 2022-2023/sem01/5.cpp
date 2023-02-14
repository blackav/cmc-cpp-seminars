#include <iostream>

const int *A0 = nullptr;
const int A1 = 10;
static const int A2 = 20;
namespace
{
    const int A3 = 30;
}
namespace A
{
    const int A4 = 40;
}

char a1[A1];
int main()
{
    using std::cout, std::endl;

    cout << sizeof(a1) << endl;
}
