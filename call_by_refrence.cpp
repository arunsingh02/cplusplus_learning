#include <iostream>

using namespace std;

void call_by_refrence_funct( // Function prototype
	int& b, // Refrence Parameter
	int c // Value Parameter
	);

int main(int argc, char const *argv[])
{
	int a = 20;
	cout << "a = " << a << " Addres of a = " << &a << endl;
	call_by_refrence_funct(a, a); // Function call
	return 0;
}

void call_by_refrence_funct(int& b, int c){ // Function declaration
	cout << "b = " << b << " Addres of b = " << &b << endl;
	cout << "c = " << c << " Addres of c = " << &c << endl;
}

/*
Output : 
a = 20 Addres of a = 0x7ffee77be7cc
b = 20 Addres of b = 0x7ffee77be7cc
c = 20 Addres of c = 0x7ffee77be7a4
*/