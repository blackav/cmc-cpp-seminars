#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

class String
{
private:
    size_t size{};
    char *str{};

public:
    String() = default;
    String(const char *str)
    {
        if (str) {
            String::size = strlen(str);
            String::str = new char[String::size + 1];
            memcpy(String::str, str, String::size + 1);
        }
    }
    String(const String &s) : size{s.size}, str{s.str}
    {
        if (str) {
            str = new char[size + 1];
            memcpy(str, s.str, size + 1);
        }
    }
    ~String()
    {
        if (str) {
            printf("str: %s\n", str);
        } else {
            printf("null\n");
        }
        delete[] str;
    }

    void swap(String &s)
    {
        std::swap(size, s.size);
        std::swap(str, s.str);
    }

    // copy-and-swap
    String &operator =(String s)
    {
        swap(s);
        return *this;
    }

    void append(char c);
    void append(char c, int cnt);
    void append(const char *str);
    void append(const String &s);

    size_t get_size() const // const String *this
    {
        return size;
    }
    const char *c_str() const
    {
        return str;
    }
};

/*
void init_string(String *dst, const char *str)
{
    dst->str = strdup(str);
    dst->size = strlen(str);
}
*/

String s2{"s2"};
String s3{"s3"};

String f(const String str)
{
    printf("%s\n", str.c_str());
    return String("from f");
}

int main()
{
    printf("main\n");
    String s1{"s1"};
    printf("after s1\n");

    String *s4 = new String{"s4"};

    String s5[16]{"s51", "s52"};

    String *s6 = new String[8]{"s61", "s62", "s63"};

    printf("after all\n");

    static String s7{"s7"};

    String s8("abbb");
    String s9 = String("xxx");
    String s10{"xxx"};
    printf("end main\n");

    f(s10);
    String s11 = s9;
    String s12 = f(s7);

    s11 = s8;

    s7 = s7;
}
