#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double z;

    //(cin >> a) >> b;
    while (cin >> z) {
        cout << "z: " << setprecision(10) << setw(32) << setfill('0') << hex << z << endl;
    }
}
