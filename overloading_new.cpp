#include <iostream>
using namespace std;

void* operator new(size_t n){ // size_t -> unsigned int
	cout << "Assigned memory" << endl;
	void *ptr;
	ptr = malloc(n);
	return ptr;
}

void operator delete(void *p){
	cout << "De-allocate memory" << endl;
	free(p);
}


void* operator new [] (size_t n, char setv){ // Fill the allocated array with setv
	cout << "Memory Allocation for array" << endl;
	void *p = operator new(n);
	memset(p, setv, n);
	return p;
}

void operator delete [] (void *p){
	cout << "Memory De-allocation for array" << endl;
	operator delete(p);
}


int main(int argc, char const *argv[])
{
	int *a = new int(5);
	cout << "Data : " << *a << endl;
	delete a;

	char *b = new('?')char[10]; // Allocate array of 10 elements and fill with '?'
	// int *b = new(1)int[10]; // Allocate array of 10 elements and fill with '#'
	cout << "b = " << (int) (*b) << endl;

	// Inserting the data in the array and print
	for (int i=0;i<10;i++){
		b[i] = i;
		cout << b[i];
	}
	cout << endl;
	delete [] b;

	return 0;
}

/*
Assigned memory
Data : 5
De-allocate memory
Memory Allocation for array
Assigned memory
b = 63
??????????
Memory De-allocation for array
De-allocate memory

*/