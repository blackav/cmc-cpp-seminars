#include <iostream>

using std::cin, std::cout, std::endl;

void g(int a, int b, int c = 0)
{
        cout << __PRETTY_FUNCTION__ << endl;
}
void g(double a, double b)
{
        cout << __PRETTY_FUNCTION__ << endl;
}
void g(const char *a, int b)
{
        cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    g(100, 200);
    g(1.0, 2.0);

    g('a', 1);
    g(1.0, 1.0f);

    //g(1.0, 2); - bad
    //g(1L, 2L); - bad
}
