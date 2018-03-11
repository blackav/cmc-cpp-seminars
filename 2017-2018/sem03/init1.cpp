#include <iostream>

int main()
{
    int x = 10;

    int y1;
    int y2 = int(10);

    int y3 = int();  // 0
    int y4(10);     // 10

    int y5();       // function declarator

    // uniform initializer
    int z1 = {};
    int z2 = { 123 };
    int z3{};
    int z4{25};

    using std::cout;
    using std::endl;

    cout << x << " " << y1 << " " << y2 << " " << y3 << " " << y4 << " " << y5 <<  " " << z1 << " " << z2 << " " << z3 <<  " " << z4 << endl;
}
