#include <iostream>

using namespace std;

extern auto func(auto) -> int;

int main()
{
    int z = func(10);
    cout << z << endl;
}
