struct A
{
	enum class E1 { A, B, C };

private:
	enum class E2 { A, B, C };

public:
	E1 e1{};
	E2 e2{};
};

int main()
{
	A a;

	a.e1 = A::E1::C;
	auto x = a.e2;
	a.e2 = x;
	A::E1 y = A::E1::B;
}
