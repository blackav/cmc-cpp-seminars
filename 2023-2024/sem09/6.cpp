#include <map>
#include <string_view>

using std::map, std::string_view;

int main()
{
	map<string_view, int> m1{{"123", 1}, {"333", 5}};

	string_view v1("12312");
	v1[2] = 'c';
}
