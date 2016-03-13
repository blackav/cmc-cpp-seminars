#include <cstdio>

int &func(int a)
{
    int b = a + 1;
    // грубая ошибка: возвращается ссылка на локальную переменную
    return b;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", func(x));
}
