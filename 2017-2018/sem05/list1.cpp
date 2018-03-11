#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> l1;
    int x;
    while (cin >> x) {
        l1.push_front(x);
    }

    for (int y : l1) {
        cout << y << endl;
    }
}
