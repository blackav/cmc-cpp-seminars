#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class String
{
    size_t  size = 0;
    char   *ptr = nullptr;

public:
    String() = default;
    String(char const *str)
    {
        if (str) {
            size = strlen(str);
            ptr = new char[size + 1];
            memcpy(ptr, str, size + 1);
        }
    }
    ~String()
    {
        cout << "~" << endl;
        delete[] ptr;
    }
    String(const String &other)
    {
        cout << "copy" << endl;
        if (other.ptr) {
            size = other.size;
            ptr = new char[size + 1];
            memcpy(ptr, other.ptr, size + 1);
        }
    }
    void swap(String &other)
    {
        std::swap(size, other.size);
        std::swap(ptr, other.ptr);
    }
    String(String &&other)
    {
        cout << "move" << endl;
        swap(other);
    }
    /*
    String &operator =(String other)
    {
        swap(other);
        return *this;
    }
    */
    String &operator = (const String &other)
    {
        String tmp(other);
        swap(tmp);
        return *this;
    }
    String &operator = (String &&other)
    {
        swap(other);
        return *this;
    }
    String &operator += (const String &other)
    {
        if (!other.size) return *this;
        if (!size) {
            *this = other;
            return *this;
        }
        size_t newsize = size + other.size;
        char *newptr = new char [newsize + 1];
        memcpy(newptr, ptr, size);
        memcpy(newptr + size, other.ptr, other.size + 1);
        delete[] ptr;
        size = newsize;
        ptr = newptr;
        return *this;
    }
    char operator[] (int index) const
    {
        return ptr[index];
    }
    char &operator[] (int index)
    {
        return ptr[index];
    }

    const char *c_str() const
    {
        if (!size) return "";
        return ptr;
    }
};

String operator + (String a, const String &b)
{
    a += b;
    return a;
}

int main()
{
    String a{"abc"};
    String b{a};

    a = a + a + a + a;
    b = a;
    b = b;

    const String &c = a;

    a[2] = 'z';

    cout << a.c_str() << endl;
    cout << c[1] << endl;

    char buf[256];
    vector<String> vs;
    while (scanf("%255s", buf) == 1) {
        //String tmp(buf);
        vs.emplace_back(String(buf));
    }

    for (const auto &s : vs) {
        cout << s.c_str() << endl;
    }
}
