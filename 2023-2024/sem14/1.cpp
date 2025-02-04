#include <iostream>

class Singleton
{
private:
	Singleton()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	constexpr Singleton & operator=(const Singleton &other) = delete;
	Singleton(const Singleton &other) = delete;

public:
	void print()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	static Singleton &instance()
	{
		static Singleton inst{};
		return inst;
	}
};

int main()
{
	std::cout << "begin" << std::endl;
	Singleton::instance().print();
}
