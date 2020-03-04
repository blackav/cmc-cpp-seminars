/* -*- mode: c++; c-basic-offset: 4 -*- */

#include <cstdlib>
#include <cstring>

#include <utility>

/*
в этом примере рассматривается класс, управляющий ресурсами
1) нетривиальный деструктор
2) конструктор копирования
3) метод swap
4) операция присваивания с использованием идиомы copy-and-swap
5) константная операция индексации
6) неконстантная операция индексации
TODO: идея для неконстантной операции индексации с помощью прокси-класса
 */
class String
{
    size_t size_{}, reserved_{};
    char *str_{};

public:
    String() = default;
    String(const char *str)
    {
        if (str) {
            reserved_ = (size_ = strlen(str)) + 1;
            str_ = new char[reserved_];
            memcpy(str_, str, reserved_);
        }
    }
    ~String()
    {
        delete [] str_;
    }

    String(const String &other)
        : size_{other.size_}, reserved_{other.reserved_}
    {
        if (other.str_) {
            str_ = new char[reserved_];
            memcpy(str_, other.str_, reserved_);
        }
    }

    void swap(String &other) noexcept
    {
        std::swap(str_, other.str_);
        std::swap(size_, other.size_);
        std::swap(reserved_, other.reserved_);
    }

    // copy-and-swap idiom
    const String &operator =(String other)
    {
        swap(other);
        return *this;
    }

    // x = str[i];
    // str[i] = y; // error!
    char operator [] (size_t index) const
    {
        return str_[index];
    }

    char &operator [] (size_t index)
    {
        return str_[index];
    }

};


int main()
{
    String z("abc");
    auto &val = z[1];

    z = "cde";
    val = 'a';
}
