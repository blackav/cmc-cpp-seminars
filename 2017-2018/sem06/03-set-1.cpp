#include <set>
#include <iostream>

using namespace std;

int main()
{
    set s1{1, 4, 7};
    s1.insert(15);

    int x;
    while (cin >> x) {
        cout << (s1.count(x) ? "YES" : "NO") << endl;
    }
}
