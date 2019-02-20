#include <iostream>

using std::cout;

int main()
{
    char c;
    char n = 0;

    using std::cin;
    using std::noskipws;

    cin >> noskipws;
    while (cin >> c) {
        cout << c;
        cout << "(" << char(n + '0') << ")" << std::endl;
        n = (n + 1) % 10;
    }
}
