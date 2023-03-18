#include <map>
#include <iostream>
#include <string>
#include <string_view>
#include <set>

using std::cout, std::endl, std::map, std::string, std::string_view, std::set;

int main()
{
    set s1{ "a", "b", "c" };
    set<string_view> s2{ "a", "b", "c" };

    for (const auto &s : s2) {
        cout << s << endl;
    }
}
