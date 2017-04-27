#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "sizeof(2) = " << sizeof(2) << endl;
	cout << "sizeof(2U) = " << sizeof(2U) << endl;
	cout << "sizeof(2L) = " << sizeof(2L) << endl;
	cout << "sizeof(2UL) = " << sizeof(2UL) << endl;
	cout << "sizeof(2.F) = " << sizeof(2.F) << endl;
	cout << "sizeof(2.) = " << sizeof(2.) << endl;
	cout << "sizeof(long double) = " << sizeof(long double) << endl;
	return 0;
}
