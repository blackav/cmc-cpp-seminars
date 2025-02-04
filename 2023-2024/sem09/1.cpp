#include <unordered_map>
#include <iostream>
#include <vector>

using std::unordered_map, std::cout, std::endl;
using std::vector;

template<>
class std::hash<vector<int>>
{
public:
	size_t operator()(const vector<int> &v) const noexcept
	{
		size_t seed = 0xdeadbeaddeadbeaf;
		std::hash<int> h{};
		for (auto x : v) {
			seed ^= h(x);
		}
		return seed;
	}
};

int main()
{
	std::unordered_map<int,double> m1{{1, 1.5}, {2, 2.6}};

	cout << m1[1] << endl;

	for (auto p : m1) {
		cout << p.first << " " << p.second << endl;
	}

	m1[3] = 3.7;
	for (auto p : m1) {
		cout << p.first << " " << p.second << endl;
	}

	vector v1{1};
	unordered_map<vector<int>, double> m2;
	m2[v1] = 3.3;
}
