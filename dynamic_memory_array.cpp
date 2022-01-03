#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// int *ar = (int *) malloc(sizeof(int) * 3); // using malloc function (return void * -> do casting to convet into int)
	int *ar = new int[3];
	// int *ar = (int *) operator new(sizeof(int) * 3); // Operator overloading
	cout << "Size of array : " << sizeof(ar) << endl;
	ar[0] = 10;
	ar[1] = 20;
	ar[2] = 30;
	cout << "Array print : " << ar << endl;
	cout << "Index print : " << ar[1] << endl;
	// free(ar)
	delete [] ar;
	// operator delete(ar) 
	return 0;
}

/*
Size of array : 8
Array print : 0x7fe22fc059c0
Index print : 20
*/