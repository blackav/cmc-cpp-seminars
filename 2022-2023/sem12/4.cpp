template<typename T>
class MyVector
{
    T *data_{};
    size_t capacity_{};
    size_t size_{};

public:
    template<typename ...Args>
    void emplace_back(Args && ...args)
    {
        T *ptr = data_ + size_;
        new (ptr) T(std::forward<Args>(args)...);
    }
};
