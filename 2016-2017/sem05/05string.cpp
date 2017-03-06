#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string z;
    vector<string> vs;
    while (getline(cin, z)) {
        vs.push_back(z);
        if (z.find("123") == string::npos) cout << "not found" << endl;
    }
    for (const auto &s : vs) {
        cout << s << endl;
    }
}
