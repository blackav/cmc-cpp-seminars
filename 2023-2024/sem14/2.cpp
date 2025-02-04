#include <iostream>
#include <memory>
#include <string_view>
#include <unordered_map>
#include <functional>
#include <stdexcept>

using std::cout, std::endl, std::shared_ptr, std::make_shared, std::string_view;
using std::unordered_map;
using std::function;

class Base
{
public:
	virtual ~Base() {}

private:
	static unordered_map<string_view, function<shared_ptr<Base> ()>> m;

public:
	static shared_ptr<Base> make(string_view id)
	{
		if (auto it = m.find(id); it != m.end()) {
			return it->second();
		}
		throw std::invalid_argument("id invalid");
	}

public:
	static void reg(string_view id, function<shared_ptr<Base>()> f)
	{
		m.insert({id, f});
	}
};
	
unordered_map<string_view, function<shared_ptr<Base> ()>> Base::m;

template<typename T>
struct Initializer
{
	Initializer(string_view id)
	{
		Base::reg(id, []() {
			return make_shared<T>();
		});
	}
};

struct D1 : public Base
{
	D1()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}

	static Initializer<D1> init;
};
Initializer<D1> D1::init("D1");

struct D2 : public Base
{
	D2()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	static Initializer<D2> init;
};
Initializer<D2> D2::init("D2");

int main()
{
	shared_ptr<Base> p1 = make_shared<D1>();
	shared_ptr<Base> p2 = make_shared<D2>();

	shared_ptr<Base> p3 = Base::make("D1");
	shared_ptr<Base> p4 = Base::make("D2");
}
