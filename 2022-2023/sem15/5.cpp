#include <any>
#include <map>
#include <iostream>
#include <string>

using std::cout, std::endl, std::any, std::map;
using std::string;
using std::make_any;

int main()
{
    map<string,any> j;

    j["1"] = make_any<int>(10);
    j["2"] = make_any<bool>(true);
    j["3"] = make_any<string>("abc");
    j["4"] = make_any<map<string,any>>();

    for (const auto &p : j) {
        if (const auto &t = p.second.type(); t == typeid(int)) {
            cout << "int: " << any_cast<int>(p.second) << endl;
        } else if (t == typeid(bool)) {
            cout << "bool: " << any_cast<bool>(p.second) << endl;
        }
    }
}
