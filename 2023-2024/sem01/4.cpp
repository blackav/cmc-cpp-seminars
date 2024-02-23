#include <format>
#include <iostream>
#include <iterator>

// using namespace std;

int
main()
{
    using std::cin, std::cout, std::format, std::endl;
    using std::format_to, std::ostream_iterator;

    int a, b;
    cin >> a >> b;

    cout << format("{}", a + b) << endl;

    ostream_iterator oi = ostream_iterator<char>(cout);
    format_to(oi, "{}\n", a + b);
}
