#include <array>
#include <iostream>

using std::array, std::cout, std::endl;

int main()
{
    array<int, 5> ai;
    array<int, 5> ai3{1, 2, 3};
    array ai4{1, 2};

    array<int, 5> ai5(ai3);

    cout << sizeof(ai) << endl;
    cout << sizeof(ai3) << endl;
    cout << sizeof(ai4) << endl;
}
