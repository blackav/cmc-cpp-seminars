#include <iostream>

using namespace std;

int *func()
{
    // элементы массива проинициализированы не будут!
    int *ptr = new int[10];
    return ptr;
}

int main()
{
    int *ptr = func(); 

    for (int i = 0; i < 10; ++i) {
        cout << ptr[i] << endl;
    }
}
