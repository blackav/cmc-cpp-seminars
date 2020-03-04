/* -*- mode: c++; c-basic-offset: 4 -*- */

/*
в этом примере рассматривается:
1) определение операции += как члена класса
2) определение бинарной операции + через +=
3) определение бинарной операции < как дружественной функции
4) определение бинарных операций <= > >= == != через операцию <
5) определение операции преобразования explicit operator bool
6) чтобы тело функции поместить вне тела класса в заголовочном файле нужен inline
 */
class Int
{
private:
    int v_{};

public:
    Int() = default;
    Int(int v) : v_{v} {}

    // +=
    const Int &operator += (const Int &v2)
    {
        v_ += v2.v_;
        return *this;   // формальное преобразование: нужно для приведения типа Int * -> Int &
    }

    // Int a, b;
    // a < b         a < 0    0 < a        
    friend bool operator < (Int v1, Int v2)
    {
        return v1.v_ < v2.v_;
    }

    // if (a)   a && b
    explicit operator bool () const
    {
        return bool(v_);
    }
};

inline bool operator == (Int v1, Int v2)
{
    return !(v1 < v2) && !(v2 < v1);
}
inline bool operator != (Int v1, Int v2)
{
    return !(v1 == v2);
}

inline Int operator +(Int v1, const Int &v2)
{
    return v1 += v2;
}

int main()
{
}

