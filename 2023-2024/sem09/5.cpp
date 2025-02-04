#include <string>
#include <string_view>
#include <iostream>

using std::string, std::string_view, std::cout, std::endl;

int main()
{
	string_view v1;
	{
		string s1 = "0123456789";

		v1 = string_view(s1.begin() + 1, s1.end() - 1);

		cout << s1 << endl;
		cout << v1 << endl;

		s1[5] = 'x';
		cout << v1 << endl;
	}

	string_view v2(v1.begin() + 1, v1.end() - 1);
	cout << v2 << endl;
}
