#include <map>
#include <iostream>
#include <utility>
#include <functional>
#include <set>

using std::cout, std::endl;
using std::map;

int main()
{
	map<int,double> m1{{1, 1.5}, {2,2.5}};
	cout << m1.size() << endl;
	cout << m1[1] << endl;
	cout << m1[3] << endl;

	const auto &m2 = m1;
	//cout << m2[4] << endl;
	
	for (std::pair<int, double> p : m2) {
		cout << p.first << " " << p.second << endl;
	}

	map<int,double,std::greater<int>> m3{};
	m3.insert({1, 1.5});
	m3.insert({2, 2.5});
	for (auto p : m3) {
		cout << p.first << " " << p.second << endl;
	}

	if (m3.count(3) > 0) {
		cout << "exists" << endl;
	}
	if (auto it = m3.find(2); it != m3.end()) {
		cout << "exists " << it->second << endl;
	}

	std::set<int> sss{1, 2, 3, 4};
}
