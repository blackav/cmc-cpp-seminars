#include <cstdint>

// (T) v
// T(v), T{v}

// static_cast, const_cast, reinterpret_cast

//static_cast<int>(d)
//static_cast<bool>(10)
//static_cast<B*>(D*)
//static_cast<B&>(D&)

//static_cast<D*>(B*)
//static_cast<D&>(B&)

struct B
{
};

struct D1 : public B
{
};

struct D2 : public B
{
};

struct B2
{
};

void f(B *b, int *p)
{
	auto d1 = static_cast<D1*>(b);
	//auto b2 = static_cast<B2*>(b);
	//auto pu = static_cast<unsigned*>(p);
	// doubtful, but ok
	auto v1 = static_cast<void*>(b);
	auto b2 = static_cast<B2*>(v1);

	auto b3 = reinterpret_cast<B2*>(b);
}

void f2(const B *b)
{
	B *bb = const_cast<B*>(b);
}

struct Fib
{
	mutable unordered_map<uint64_t, uint64_t> cache;

	uint64_t get(uint64_t n) const noexcept
	{
		if (auto it = cache.find(n); it != cache.end()) {
			return it->second;
		}
		if (n <= 1) return 1;
		auto val = get(n - 1) + get(n - 2);
/*
		auto t = const_cast<Fib*>(this);
		t->cache.insert({n, val});
*/
		return val;
	}
};

int main()
{
}
