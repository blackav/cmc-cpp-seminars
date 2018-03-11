#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

// using std::basic_string<char> std::string;

int main()
{
    std::string val1;
    std::string val2{"abcd"};
    std::string val3(10, 'z');
    std::string val4{"abcdef", 4};
    std::string val5{'a', 'b', 'c'};
    std::string val6{val2, 2, 1};
    std::string val7{val2, 2};

    cout << val1 << endl;
    cout << val2 << endl;
    cout << val3 << endl;
    cout << val4 << endl;
    cout << val5 << endl;
    cout << val6 << endl;
    cout << val7 << endl;

    val1.assign(val3, 1, 2);
    cout << val1 << endl;

    cout << val2.size() << " " << val4.length() << std::endl;
    printf("%s\n", val7.c_str());
}
