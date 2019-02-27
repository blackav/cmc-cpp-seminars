

int f(int x, int y = 1, int z = 2);

int f(double x);

int f(double x, double y, int z = 10);;

int main()
{
    f(10);
    f(10, 11);
    f(10, 11, 12);

    f(1.2, 4.4);
}
