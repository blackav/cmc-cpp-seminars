#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> li;
    int z;
    while (cin >> z) {
        li.push_front(z);
    }

    li.pop_front();

    auto ii = li.begin();
    ++ii;
    ++ii;
    li.insert(ii, 100);

    for (auto j = li.rbegin(); j != li.rend(); ++j) {
    }
    
    for (auto x : li) {
        cout << x << endl;
    }
}
