template<typename T>
class MyVector
{
public:
    using value_type = T;
    using reference_type = T&;

    static constexpr bool is_int = true;
};

template<>
class MyVector<double>
{
public:
    static constexpr bool is_int = false;
};

int main()
{
    MyVector<int> v;

    v::value_type;
}
