void
f(int a, int b, int c = {}, int d = 4)
{
}
void
f(int a, double b)
{
}
void
f(double a, float b, long c)
{
}

int
main()
{
    f(1, 2);
    f(1, 2, 3);
    f(1, 2, 3, 4);
}
