#include <string>
#include <iostream>

using std::string, std::cout, std::endl;
using std::u8string;

class mystring
{
	char *ptr_{};
	size_t cap_{};
	size_t size_{};
};

// small string optimization
class ssostring
{
	char *ptr_{};
	size_t size_{};
	union {
		size_t cap_;
		char inc[16];
	};
};

int main()
{
	string s1 = "12345";
	string s2(10, 'x');

	cout << s1 << endl;
	cout << s2 << endl;
	string s3(s2, 2, 5);
	cout << s3 << endl;

	string s4(s3, 1, string::npos);
	cout << s4 << endl;

	std::basic_string<char> s5 = s4;

	u8string s6 = u8"12345";	
	u8string s7 = u8"привет!";
	//cout << s7 << endl;
	//
	cout << sizeof(s5) << endl;
	cout << sizeof(s7) << endl;
	cout << sizeof(mystring) << endl;

	printf(">%s<\n", s1.c_str());
}
