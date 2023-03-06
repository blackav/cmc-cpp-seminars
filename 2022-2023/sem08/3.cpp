#include <string>
#include <iostream>
#include <string_view>

using std::string, std::cout, std::endl, std::string_view;

void f(const string &s)
{
    for (auto c : s) {
        cout << c;
    }
    cout << endl;
}

void g(string_view sv)
{
    for (auto c : sv) {
        cout << c;
    }
    cout << endl;
}

int main()
{
    string s1;
    string s2("sadfsadfa");

    cout << sizeof(s1) << endl;
    cout << s1.length() << endl;
    cout << s1.capacity() << endl;
    cout << sizeof(s2) << endl;
    cout << s2.length() << endl;
    cout << s2.capacity() << endl;

    string s3("121231231231123123123");
    cout << sizeof(s3) << endl;
    cout << s3.length() << endl;
    cout << s3.capacity() << endl;

    cout << s3.c_str() << endl;

    f(s3);
    f("123123123123123uyiuyiuyiuyiuyiuyiyiyiuy");

    g(s3);
    g("123123123123123uyiuyiuyiuyiuyiuyiyiyiuy");
}
