#include <iostream>
#include <format>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <type_traits>
#include <iterator>

using std::cin, std::cout, std::format, std::endl;
using std::vector, std::list, std::set, std::string;

template<typename T>
struct Plus
{
	T operator()(T a, T b) { return a + b; }
};

template<typename T, typename F = Plus<typename T::value_type>>
auto sum(const T& v, typename T::value_type s = {}, F f = {})
{
	for (auto &x : v) {
		s = f(s, x);
	}
	return s;
}

template<typename T, typename F = Plus<typename T::value_type>>
typename T::value_type sum(T beg, T end, typename T::value_type s = {}, F f = {})
{
	for (auto i = beg; i != end; ++i) {
		s = f(s, *i);
	}
	return s;
}

template<typename T>
auto sum2(const T& v)
{
	typename std::remove_const<typename std::remove_reference<decltype(*std::begin(v))>::type>::type s{};
	for (auto &x : v) {
		s += x;
	}
	return s;
}

int main()
{
	vector v1{1, 2, 3, 4};

/*
	int s = 0;
	for (auto x : v1) {
		s += x;
	}
*/
	auto s = sum(v1);
	cout << format("{}", s) << endl;

	list l1{1.0, 2.0, 3.0, 4.0};
	auto s2 = sum(l1);
	cout << format("{}", s2) << endl;

	set<string> ss1{"c", "a", "b"};
	auto s3 = sum(ss1, "xxx");	
	cout << format("{}", s3) << endl;

	//vector<vector<int>> vv1{{1}, {2}, {3}};
	//auto s4 = sum(vv1);
	
	auto s6 = sum2(v1);
	cout << format("{}", s6) << endl;

	int v5[] = {1, 2, 3};
	auto s5 = sum2(v5);
	cout << format("{}", s5) << endl;

	auto s7 = sum(v1, 1, [](auto s, auto x) { return s * x; });
	cout << format("{}", s7) << endl;

	auto s8 = sum(std::begin(v1), std::end(v1) - 1, 1, [](auto s, auto x) { return s * x; });
	cout << format("{}", s8) << endl;
}
