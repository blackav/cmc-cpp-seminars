#include <string>
#include <iostream>

using std::string, std::cout, std::endl;

struct A
{
	string name_;

	/*
	void set_name(const string &name)
	{
		name_ = name;
	}
	*/
	void set_name(string name) noexcept
	{
		name_ = std::move(name);
		//std::swap(name_, name);
	}
};

int main()
{
	A a;

	a.set_name("1234");
	a.set_name(string("5678"));
}
