#include <unordered_map>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    unordered_map<int, int> um{{11, 2}, {3, 4}, {5, 6}};
    vector vv{1, 2, 3, 4, 5};
    copy(vv.begin(), vv.end(), ostream_iterator<int>(cout, "\n"));
    for (const auto &p : um) {
        cout << p.first << endl;
    }
}
