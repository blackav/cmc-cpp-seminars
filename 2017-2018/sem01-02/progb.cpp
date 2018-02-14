#include <iostream>

using namespace std;

void zzz(int a, int b, double c = 3.3, const char *ptr = "aaa")
{
    cout << a << " " << b << " " << c << " " << ptr << endl;
}


int main()
{
    zzz(10, 20);
    zzz(100, 200, 56.6);
    zzz(1, 2, 3.6, "zzzz");
    //zzz(1, 2, , "asdf");
}
