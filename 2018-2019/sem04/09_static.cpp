struct X
{
    static int a;
    int b;

    static int foo()
    {
        //b++;
        a++;
        return 1;
    }
    int bar();
};

int X::a = 10;

int main()
{
    X::a = 11;

    X::foo();

    X x, *px = new X, &rx = x;

    x.foo();
    px->foo();
    rx.foo();
}
