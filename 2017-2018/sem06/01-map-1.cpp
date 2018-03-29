#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, double> m1;

    string a;
    double b;
    while (cin >> a) {
        cin >> b;

        m1[a] = b;
    }

    for (std::map<string, double>::const_iterator ii = m1.begin(); ii != m1.end(); ++ii) {
        cout << "key: " << (*ii).first << endl;
        cout << "value: " << ii->second << endl;
    }
}
