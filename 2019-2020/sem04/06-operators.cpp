struct Int
{
  int v_{};

  Int() = default;
  Int(int v) : v_{v} {}
  //Int(const Int&) = delete;

  Int operator+(const Int &v2) const
  {
    return v_ + v2.v_;  // Int(int) -> Int(const Int &)
    // return value optimization: Int(int)
  }
};

Int operator *(const Int &v1, const Int &v2)
{
  return v1.v_ * v2.v_;
}

Int operator -(const Int &v1, const Int &v2)
{
  return v1.v_ * v2.v_;
}

Int operator -(const Int &v)
{
  return { -v.v_ };
}

// for (Int i = 0; i < z; --i)
// for (Int i = 0; i < z; i++)

Int operator++(Int &v, int a)
{
  Int t{v};
  ++v.v_;
  return t;
}
Int &operator--(Int &v, int a)
{
  Int t{v};
  ++v.v_;
  return t;
}

// -- -- -- -- x;

Int &operator--(Int &v)
{
  --v.v_;
  return v;
}

int main()
{
  Int a, b, c;

  c = a * b;

  c = b ------- a;
  Int d = (a++ + --b) * -c;

  Int e = operator*((operator++(a,0)).operator+(operator--(b)), operator-(c));
}


// TODO: =, +=, *= ...
// TODO: ->, [], ()
// TODO: <=>, <, <=, >, >=, ==, !=
// Not supported: ., ::, ?:
