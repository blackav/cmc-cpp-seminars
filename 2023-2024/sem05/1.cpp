/*
+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= <=>(since C++20) && || ++ -- , ->* -> ( ) [ ]
*/

// binary: + - / * % ^ & | << >>
// += -= /= *= %= ^= &= |= <<= >>=
// + - ~ ! *?
// == != < <= > >= <=>
// ++ --


// не нужно: && ||

#include <iostream>
#include <format>

struct A
{
private:
  int v_{};

public:
  A(int v) noexcept : v_(v) {}

  A operator +(A b) const
  {
    return A(v_ + b.v_);
  }

  friend A operator-(A a, A b);
  friend A operator *(A a, A b)
  {
    return A(a.v_ * b.v_);
  }

  const A& operator /= (A b) noexcept
  {
    v_ /= b.v_;
    return *this;
  }

  A operator -() const noexcept
  {
    return A(-v_);
  }
  friend A operator +(A a) noexcept
  {
    return a;
  }

  // std::strong_ordering { less, greater, equal };
  //friend auto operator <=> (A a, A b) = default;
  //friend bool operator < (A a, A b) = default;
  friend std::strong_ordering operator <=> (A a, A b) noexcept
  {
    if (a.v_ > b.v_) return std::strong_ordering::less;
    if (a.v_ < b.v_) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
  }
  friend bool operator ==(A a, A b) = default;
  
  /*
  friend bool operator < (A a, A b) noexcept
  {
    return a.v_ < b.v_;
  }
  friend bool operator == (A a, A b) noexcept
  {
    return !(a < b) && !(b < a);
  }
  friend bool operator <= (A a, A b) noexcept
  {
    return (a < b) || (a == b);
  }
  */

  const A & operator++() noexcept
  {
    ++v_;
    return *this;
  }
  A operator++(int _) noexcept
  {
    auto tmp = *this;
    ++v_;
    return tmp;
  }

  A operator()(int x) const noexcept
  {
    return A(v_ + x);
  }
  bool operator() (int x, int y) const noexcept
  {
    return x < y;
  }
};



A operator -(A a, A b)
{
  return A(a.v_ + b.v_);
}

A operator /(A a, A b)
{
  a /= b;
  return a;
}

// a+b+c -> (a+b)+c
// a=b=c -> a=(b=c)
// a+b*c -> a+(b*c)

int main()
{
  A a{5}, b{6};

  auto c = a + b;
  auto d = a - b;

  auto e = a + 1;
  //auto f = 1 + a;
  auto f = a - 1;
  auto g = 1 - a;

  auto b1 = a < b;
  auto b2 = a <= b;
  auto b3 = a > b;
  auto b4 = a >= b;
  auto b5 = a == b;
  auto b6 = a != b;

  auto h = operator-(a, b);
  auto i = a.operator+(b);

  auto j = a(100);
  auto k = a(1, 222);
}
