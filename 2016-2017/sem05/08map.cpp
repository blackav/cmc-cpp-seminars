#include <map>
#include <iostream>
#include <string>
#include <vector>

#include <set>

using namespace std;

int main()
{
    map<string, int> mm;

    mm["abc"] = 10;
    mm["df"] = 15;

    cout << mm["abc"] << " " << mm["def"] << endl;

    const auto &m2 = mm;

    if (m2.find("aaa") == m2.end()) cout << "not found" << endl;

    for (map<string, int>::const_iterator ii = mm.cbegin(); ii != mm.cend(); ++ii) {
        pair<string, int> pp = *ii;
        cout << pp.first << " " << pp.second << endl;

        cout << ii->first << " " << ii->second << endl;
    }

    map<string, map<string, map<int, vector< vector< string>>>>> zzz;

    zzz["a"]["b"][3][10][14];

    set<int> is;

    is.insert(25);
    if (is.find(100) != is.end()) {}
}
