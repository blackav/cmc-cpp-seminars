#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

using std::cout, std::endl, std::unordered_map, std::string, std::string_view;

struct A
{
    int v_{};

    A(int v) : v_(v) {}

    friend class std::hash<A>;
    auto operator <=> (const A &other) const = default;
};

template<> class std::hash<A>
{
public:
    size_t operator() (A a) const
    {
        return size_t(a.v_);
    }
};

int main()
{
    unordered_map<A, int> m1;

    
    m1.emplace(100, 100);

}
