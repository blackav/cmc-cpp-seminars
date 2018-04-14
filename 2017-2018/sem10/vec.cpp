#include <iostream>
#include <utility>
#include <memory>

/*
 реализация некоторых методов шаблонного класса vector:

 * создание/копирование/удаление объекта с помощью placement new;
 * передача аргументов в произвольный конструктор с помощью perfect
   forwarding и создание объекта "на месте" с помощью placement new
   в методе assign
*/

template<typename T>
class MyVector
{
    T *ptr = nullptr;
    size_t alloc = 0, used = 0;

public:
    void swap(MyVector &other)
    {
        std::swap(ptr, other.ptr);
        std::swap(alloc, other.alloc);
        std::swap(used, other.used);
    }
    MyVector() = default;
    MyVector(const MyVector &o) : alloc(o.alloc), used(o.used)
    {
        if (o.alloc > 0) {
            ptr = (T*) ::operator new(alloc * sizeof(T));
            //ptr = new T[alloc];
            for (size_t i = 0; i < used; ++i) {
                new (&ptr[i]) T(o.ptr[i]);
            }
        }
    }
    ~MyVector()
    {
        if (used > 0) {
            for (ssize_t i = ssize_t(used) - 1; i >= 0; --i) {
                ptr[i].~T();
            }
        }
        ::operator delete(ptr);
    }

    template <typename ... TT>
    void assign(size_t index, TT &&... args)
    {
        ptr[index].~T();
        new (&ptr[index]) T(std::forward<TT>(args)...);
    }
};

int main()
{
    MyVector<int> vvv;
    MyVector<int> v2 = vvv;

    vvv.assign(3, 2);    
}
