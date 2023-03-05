#include <iostream>
#include <vector>
#include <list>

using std::cout, std::endl, std::vector, std::list;

int main()
{
    vector<int> vi{1, 2, 4, 5, 6};
    vector vi2{1, 2, 3, 4};
    vector<int> vi3(16);
    vector<int> vi4(16, 1);
    vector<int> vi5({1, 2});

    list<int> li1{1, 100, 200}; 

    std::vector<int>::iterator it = vi.begin();
    std::vector<int>::const_iterator it2 = vi.cbegin();
    std::vector<int>::reverse_iterator it3 = vi.rbegin();
    std::vector<int>::const_reverse_iterator it4 = vi.crbegin();

    auto it5 = vi.begin();

    for (auto it6 = vi.begin() + 2; it6 < vi.end() - 1; ++it6) {
        cout << *it6 << endl;
    }

    for(auto it7 = li1.begin(); it7 != li1.end(); ++it7) {
        cout << *it7 << endl;
    }

    for (const auto &v : li1) {
        cout << v << endl;
    }
}
