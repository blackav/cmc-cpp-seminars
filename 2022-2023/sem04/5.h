struct A
{
    void f()
    {
    }
    void f() const;
};

inline void A::f() const
{
}

