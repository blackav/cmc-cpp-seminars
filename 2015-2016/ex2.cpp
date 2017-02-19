#include <iostream>
#include <signal.h>

using namespace std;

void fpeh(int s)
{
    cout << "Oops" << endl;
    throw 1;
}

int main()
{
    signal(SIGFPE, fpeh);
    while (1) {
        int a, b, c;
        cin >> a >> b;
        try {
            c = a / b;
            cout << c << endl;
        } catch (...) {
            cout << "div by 0" << endl;
        }
    }
}
