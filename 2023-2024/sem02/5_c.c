int func2(int x);

int _Z5func3i(int x);

int
func(int x)
{
    int y = _Z5func3i(x);
    return func2(x) + 1 + y;
}
