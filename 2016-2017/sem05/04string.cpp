#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string abc(10, 'a');
    cout << abc << endl;
    string z;
    vector<string> vs;
    while (cin >> z) {
        if (z == abc) abort();
        vs.push_back(z);
    }
    for (const auto &s : vs) {
        cout << s << endl;
    }
}
