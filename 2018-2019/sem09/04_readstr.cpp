#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> vs;
    string s;

    while (cin >> s) {
        // строка s будет перенесена в вектор, а не скопирована
        vs.push_back(move(s));
    }

    for (const auto &z : vs) {
        cout << z << endl;
    }
}
