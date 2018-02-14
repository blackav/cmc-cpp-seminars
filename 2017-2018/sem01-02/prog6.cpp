#include <iostream>

using namespace std;

enum Enum1 { C1, C2, C3 };

enum class Enum2 { C4, C5, C6 };

ostream & operator << (ostream &out, Enum2 x)
{
    return out << "Ha: " << (int) x << std::endl;
}



int main()
{
    Enum1 d = C1;
    d = (Enum1) (d + 1);

    Enum2 e = Enum2::C6;
    //e = (Enum2) (e + 1);
    cout << d << endl;
    e = (Enum2) 10000;
    //e = static_cast<Enum2>(100);
    cout << e << endl;
}
