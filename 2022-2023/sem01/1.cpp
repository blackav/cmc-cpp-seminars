#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
    //int a = 0;
    //int a(0);
    //int a{2};
    //int a{};
    //int a(2.0);
    int a{};

    [[maybe_unused]]
    int b;

    //[[maybe_unused]]
    //using tt = int;

    using std::cin;
    cin >> a >> b;

    using std::cout, std::endl;
    cout << std::dec << std::setfill('0') << std::setw(10) << a + b << endl;
}
