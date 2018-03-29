#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    string s;
    vector<string> v;
    while (cin >> s) {
        v.push_back(move(s));
    }

    for (const auto &s : v) {
        cout << s << endl;
    }
}
