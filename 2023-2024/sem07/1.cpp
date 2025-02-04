#include <utility>

// unlimited copy/move: std::string, std::vector, std::complex
// only move: std::thread
// nothing: std::mutex

// non-copyable, non-moveable
struct A
{
	int x_{};

	A(int x = 0) : x_(x) {}

	A(const A &other) = delete;
	const A & operator=(const A& other) = delete;
};

// non-copyable, movable
struct B
{
	int x_{};

	B(int x = 0) : x_(x) {}

	B(const B &other) = delete;
	const B & operator=(const B& other) = delete;
	B(B &&other) = default;
	constexpr B &operator=(B&& other) = default;
};

// copyable, non-moveable
struct C
{
	int x_{};

	C(int x = 0) : x_(x) {}

	C(const C &other) = default;
	constexpr C & operator=(const C& other) = default;
	C(C &&other) = delete;
	constexpr C &operator=(C&& other) = delete;
};

int main()
{
	A a{100};

	//A a2{a};
	A a3{0};

	//a3 = a;

	//A a4{std::move(a)};
	//a3 = std::move(a);

	B b1{1};
	B b3{3};

	//B b2{b1};
	//b3 = b1;
	B b2{std::move(b1)};
	b3 = std::move(b1);

	C c1{1};
	C c3{3};

	C c2{c1};
	c3 = c1;
	//C c4{std::move(c1)};
	//c3 = std::move(c1);
}
