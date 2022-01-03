#include <iostream>

using namespace std;

void swap(int &, int &); // Function Prototype and Call-by-reference


int main(int argc, char const *argv[])
{
	int a = 20, b = 35;
	cout << "Before Swap a = " << a << " and b = " << b << endl;
	swap(a, b);
	cout << "After Swap a = " << a << " and b = " << b << endl;
	return 0;
}

void swap(int &x, int &y){ // Function Defnition
	int t;
	t = x;
	x = y;
	y = t;
}

/*
Output:
Before Swap a = 20 and b = 35
After Swap a = 35 and b = 20
*/