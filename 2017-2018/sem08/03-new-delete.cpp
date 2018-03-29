#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int *p = new int{100};

    int *q = new (std::nothrow) int{200};

    delete p;
    delete q;


    int *a1 = new int[10];
    a1[0] = 10101;
    delete[] a1;

    a1 = new int[10]{1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 10; ++i) {
        cout << a1[i] << endl;
    }

    delete[] a1;
}
