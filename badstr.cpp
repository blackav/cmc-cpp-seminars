#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string s1("a");
    string s2("b");
    // грубая ошибка: временный объект (s1 + s2) будет уничтожен после вычисления выражения
    auto *p = (s1 + s2).c_str(); // p - const char *
    // 'p' здесь указывает "в никуда"
    printf("%s\n", p);
}
