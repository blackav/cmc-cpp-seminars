#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>

/*
реализация семантики переноса на примере класса строки
 */

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
        //printf("copy constr\n");
        if (str) {
            str = new char[size + 1];
            memcpy(str, s.str, size + 1);
        }
    }
    String(String &&s) : size{s.size}, str{s.str}
    {
        //printf("move constr\n");
        // объект s должен остаться в целостном состоянии!
        // для него будет вызываться деструктор
        s.size = 0;
        s.str = nullptr;
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
    // и обычное присваивание, и присваивание с rvalue поддерживается автоматически
    // (будет использоваться либо конструктор копирования, либо конструктор переноса)
    String &operator =(String s)
    {
        swap(s);
        return *this;
    }

    /*
    // так может выглядеть присваивание с переносом
    String &operator =(String &&s)
    {
            if (&s == this) return;

            //destroy this
            //move s
    }
    */

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

String f(String str)
{
    String res("from f");
    String res2("from f2");

    if (rand() % 2) {
        return res2;
    }

    printf("%s\n", str.c_str());
    return res;
}

/*
 компиляторы обязаны выполнять return value optimization!
 при return не будет ни копирования, ни переноса
 */
String g(const String str)
{
    String res("from f");

    printf("%s\n", str.c_str());
    return res;
}

int main()
{
    String a("");

    auto b = f(std::move(a));
    printf("%s\n", b.c_str());

    b = a;
    b = std::move(a);
}
