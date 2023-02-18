#include <iostream>

using std::cin, std::cout, std::endl;

void g(int a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(char a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(unsigned char a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(long long a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(const char *s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(char *s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(bool a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    g('0');
    g(48);

    unsigned char c = '0';
    g(c);

    short s = 48;
    g((char) s);

    unsigned int ui = 100;
    g(int(ui));

    long l = 200;
    g(static_cast<long long>(l));

    g("assa");

    char *p = new char[10]{"12121"};
    g(p);

    g(0);

    const char *pp = 0;
    g(pp);

    //g(nullptr);
    g(false);

    g(1 > 2);
    g(1 && 2);
}
