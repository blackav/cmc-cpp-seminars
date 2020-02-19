#include <iostream>

using namespace std;

int *func()
{
    // в этом примере массив будет проинициализирован нулевыми значениями
    int *ptr = new int[10]{};
    return ptr;
}

int main()
{
    int *ptr = func(); 

    for (int i = 0; i < 10; ++i) {
        cout << ptr[i] << endl;
    }
}
