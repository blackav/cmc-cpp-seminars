#include <iostream>

enum A
{
	B = 1, C = 2, D = 4, E = 8
};

enum class AA
{
	BB = 1, CC = 2, DD = 4, EE = 8,
};

int main()
{
	A a = B;
	A b = A(B | D);
	A c = A(5);
	int d = E;

	AA aa = AA::BB;
	//	AA bb = AA::BB | AA::DD;
	AA cc = AA(6);
	int dd = int(AA::EE);
}
