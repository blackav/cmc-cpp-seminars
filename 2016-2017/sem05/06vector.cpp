#include <vector>
#include <iostream>

using namespace std;

int main()
{
    std::vector<int> a;
    int x;
    while (std::cin >> x) {
        a.push_back(x);
    }

    std::vector<int>::iterator i1 = a.begin();
    std::vector<int>::const_iterator i2 = a.cend() - 1;

    std::vector<int>::reverse_iterator i3 = a.rbegin();
    std::vector<int>::const_reverse_iterator i4 = a.crend() - 1;

    auto i5 = a.begin() + 3;
    (void) i5;

    std::cout << *i1 << " " << *i2 << " " << *i3 << " " << *i4 << std::endl;

    for (auto i1 = a.cbegin(); i1 != a.cend(); ++i1) {
        cout << *i1 << endl;
    }
    for (auto j2 = a.rbegin(); j2 != a.rend(); ++j2) {
        cout << ++ * j2 << endl;
    }

    for (auto xx : a) {
    }
    for (auto tmp = a.cbegin(); tmp != a.cend(); ++tmp) {
        auto xx = *tmp;
    }
}
