#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

int main()
{
    int a = 100, b = 200;

    cout << a + b << endl;
    //operator << (cout, a + b);
    cout.operator<<(a + b);

    string s{"123"};
    operator<<(cout, s);
    //cout.operator<<(s);
}
