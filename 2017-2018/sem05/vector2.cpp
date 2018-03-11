#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1;
    int x;

    while (cin >> x) {
        v1.push_back(x);
    }

    v1.pop_back();
    cout << v1.back() << endl;


    v1.insert(v1.begin() + 2, 100400);
    v1.erase(v1.begin() + 2, v1.end() - 2);

    for (auto y : v1) {
        cout << y << endl;
    }
}
