#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, double, greater<string>> m1;

    //map m2{pair{10, 2.0},pair{14, 1.5}};

    vector v1{1.5, 2.0};
    vector v2(10, 'a');

    string a;
    double b;
    while (1) {
        cin >> a;
        if (a == "END") break;
        cin >> b;

        //m1[a] = b;
        //m1.insert(pair<string, double>{a, b});
        m1.insert(pair{a, b});
        //m1.emplace(a, b);
    }

    while (cin >> a) {
        if (auto ii = m1.find(a); ii != m1.end()) {
            cout << ii->second << endl;
        } else {
            cout << "NONE" << endl;
        }
    }

    /*
    if (decl; expr) {}

    ->
    {
        decl;
        if (expr) {}
    }
    */

    /*
    for (auto ii = m1.begin(); ii != m1.end(); ++ii) {
        cout << "key: " << (*ii).first << endl;
        cout << "value: " << ii->second << endl;
    }
    */
    /*
    for (const auto &p : m1) {
        cout << "key: " << p.first << endl;
        cout << "value: " << p.second << endl;
    }
    */
}
