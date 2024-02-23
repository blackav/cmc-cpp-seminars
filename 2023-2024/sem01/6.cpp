#include <iostream>
#include <format>

int
main()
{
    int s{};
    int x;

    using std::cin;
    /*
            while (true) {
                    cin >> x;
                    //if (cin.fail()) break;
                    //if (!cin.operator bool()) break;
                    if (cin) {
                            s += x;
                    } else {
                            break;
                    }
            }
    */
    while (cin >> x) {
        s += x;
    }
    std::cout << std::format("{}\n", s);
}
