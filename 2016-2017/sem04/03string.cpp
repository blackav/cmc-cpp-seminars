#include <iostream>
#include <string.h>

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
        delete[] ptr;
    }
    String(const String &other)
    {
        if (other.ptr) {
            size = other.size;
            ptr = new char[size + 1];
            memcpy(ptr, other.ptr, size + 1);
        }
    }
};

int main()
{
    String a{"abc"};
    String b{a};
}
