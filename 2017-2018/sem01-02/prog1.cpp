#include <iostream>
#include <iomanip>

// std::cin ~ stdin
// std::cout ~ stdout
// std::cerr ~ stderr

namespace
{
    int c;
}

namespace A { namespace B { namespace C {
    int a;
}}}

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b;

    cin >> std::hex >> a >> b;
    c = a + b;
    // "%016x"
    cout << std::hex << std::setw(16) << std::setfill('0') << c << " " << c << endl;
    cout << std::dec << c << "\n";
}
