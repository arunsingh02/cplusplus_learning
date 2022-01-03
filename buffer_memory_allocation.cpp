#include <iostream>
using namespace std;

// Placement new in c++
int main(int argc, char const *argv[])
{
	unsigned char buf[sizeof(int) * 2]; // Buffer on stack
	int *pInt = new (buf + 0) int(3); // First allocation of int ( + 0)
	int *qInt = new(buf + sizeof(int)) int(5); // Second allocation of int ( + 4)

	int *bAdd = (int *) (buf + 0);
	int *cAdd = (int *) (buf + sizeof(int));

	cout << "Address " << pInt << " " << bAdd << endl;
	cout << "Address " << qInt << " " << cAdd << endl;

	cout << "Value " << *pInt << " " << *bAdd << endl;
	cout << "Value " << *qInt << " " << *cAdd << endl;

	// 	No delete for placement new.
 	return 0;
}

/*
Address 0x7ffee9df47c0 0x7ffee9df47c0
Address 0x7ffee9df47c4 0x7ffee9df47c4
Value 3 3
Value 5 5
*/