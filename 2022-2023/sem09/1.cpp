#include <map>
#include <iostream>
#include <string>
#include <string_view>

using std::cout, std::endl, std::map, std::string, std::string_view;

void f(const map<string, int> &mm)
{
    //cout << mm["D"] << endl;

    auto it = mm.find("D");
    if (it != mm.end()) {
        cout << it->second << endl;
    }

    if (auto it2 = mm.find("C"); it2 != mm.end()) {
        cout << it2->first << endl;
    }
}

int main()
{
    // std::pair<string, int>
    // .first, .second
    map<string, int> m1{
        { "A", 1 },
        { "B", 2 },
    };

    cout << m1["A"] << endl;
    cout << m1["C"] << endl;
    ++m1["B"];
    cout << m1["B"] << endl;

    // inefficient
    if (m1.count("A") == 1) {
        m1["A"] += 100;
    }

    m1.insert({ "K", 1212 });
    m1.emplace("L", 111);

    for (const auto &p : m1) {
        cout << p.first << " " << p.second << endl;
    }

    map<string_view, int> m2{ { "A", 100 }, { "B", 200 } };
}
