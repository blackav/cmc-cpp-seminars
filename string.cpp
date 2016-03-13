#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class mystring
{
    char *str = nullptr;
    size_t len = 0;

public:
    // этот конструктор работает как конструктор по умолчанию и как конструктор преобразования
    mystring(const char *s = nullptr)
    {
#ifdef DEBUG
        cerr << "mystring(";
        if (s) {
            cerr << s;
        }
        cerr << ")" << endl;
#endif

        if (s) {
            len = strlen(s);
            str = new char[len + 1];
            memcpy(str, s, len + 1);
        }
    }
    ~mystring()
    {
#ifdef DEBUG
        cerr << "~mystring(";
        if (str) {
            cerr << str;
        }
        cerr << ")" << endl;
#endif

        delete[] str;
    }

    // конструктор копирования
    mystring(const mystring &other)
        : str(other.str), len(other.len)
    {
#ifdef DEBUG
        cerr << "mystring(mystring:";
        if (str) {
            cerr << str;
        }
        cerr << ")" << endl;
#endif

        if (str) {
            str = new char[len + 1];
            memcpy(str, other.str, len + 1);
        }
    }

    // операция присваивания
    mystring &operator = (const mystring &other)
    {
#ifdef DEBUG
        cerr << "operator =(mystring:";
        if (str) {
            cerr << str;
        }
        cerr << ")" << endl;
#endif

        if (&other == this) return *this;

        mystring tmp{other};
        swap(tmp);

        return *this;
    }

    void swap(mystring &other)
    {
        std::swap(str, other.str);
        std::swap(len, other.len);
    }

    bool operator!() const
    {
        return !len;
    }

    char &operator[] (size_t ind)
    {
        return str[ind];
    }
    char operator[] (size_t ind) const
    {
        return str[ind];
    }

    friend mystring operator+ (const mystring &s1, const mystring &s2);

    // конструктор переноса
    mystring(mystring &&other)
        : str(other.str), len(other.len)
    {
#ifdef DEBUG
        cerr << "mystring(&&:";
        if (str) {
            cerr << str;
        }
        cerr << ")" << endl;
#endif

        other.str = nullptr;
        other.len = 0;
    }

    // операция присваивания с переносом
    mystring &operator=(mystring &&other)
    {
#ifdef DEBUG
        cerr << "operator =(&&:";
        if (str) {
            cerr << str;
        }
        cerr << ")" << endl;
#endif

        swap(other);
        return *this;
    }
    friend ostream & operator <<(ostream &f, const mystring &s);
};

mystring operator+ (const mystring &s1, const mystring &s2)
{
    if (!s1.len) return s2;
    if (!s2.len) return s1;

    mystring res;
    res.len = s1.len + s2.len;
    res.str = new char[res.len + 1];
    memcpy(res.str, s1.str, s1.len);
    memcpy(res.str + s1.len, s2.str, s2.len + 1);
    return res;
}

mystring str1;
mystring str2("abcd");

ostream & operator <<(ostream &f, const mystring &s)
{
    f << s.str;
    return f;
}

istream & operator >>(istream &f, mystring &s)
{
    int c = f.get();
    while (isspace(c)) c = f.get();

    mystring res;
    while (!isspace(c)) {
        char buf[2];
        buf[0] = c;
        buf[1] = 0;
        res = res + mystring(buf);
        
        c = f.get();
    }

    return f;
}

int main()
{
    mystring str3;
    mystring str4("efgh");
    mystring str5{str4};

    mystring str6("aaa");
    str6 = str3;
    str6 = str5;

    str5 = str5;

    str5 = str5 + str4;
    str5 = str5 + "klmn";
    str5 = "xyz" + str5;

    str3 = std::move(str5); // помечаем, что 'str5' далее не нужен

    str5 = str3;

    for (int i = 0; i < 2; ++i) {
        char buf[64];
        snprintf(buf, sizeof(buf), "%d", i);
        mystring stri(buf);
    }
}











