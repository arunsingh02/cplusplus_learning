#include <iostream>

using namespace std;

class Complex
{
	double re_, im_;
	public:
		// Constructor
		Complex(double re=2.0, double im=1.0): 	// Default argument in constructor E3: Initialize the data member in order of init in class creation time
			re_(re), im_(im) 					// Params used to initialize 
		{ // E4: Object life start
			cout << "Constructor called." << endl;
		}

		double normalize(){ // E6: Object calling the func
			return sqrt(re_*re_ + im_*im_);
		}

		void printer();

		~Complex();
};

Complex::~Complex(){
	cout << "Destructor called." << endl;
}

void Complex::printer(){
	double result = normalize();
	cout << " Square root : " << result << endl;
}

int main(int argc, char const *argv[]) // E1 : Allocate memory in stackframe
{
	Complex c(4.2, 5.3), 		// Complex::Complex(4.2, 5.3) E2 : Call Ctor
			d = { 1.6, 2.9 },	// Complex::Complex(1.6, 2.9)
			e;					// Complex::Complex() // Default value will take place

	/*
	cout << "Calling Ctor with new : " << endl;
	Complex* pc = new Complex(1.2, 3.2); // new will allocate memory and call Ctor also.
	Complex* pd = new Complex[2]; // Call Ctor 2 times
	*/
	
	c.printer(); // E5: Object Use
	d.printer();
	e.printer();
	return 0; // E7: Dtor called (Dtor called in reverse order (LIFO))
} // E8: De-allocate the memory from stackframe

/*
Constructor called.
Constructor called.
Constructor called.
 Square root : 6.7624
 Square root : 3.3121
 Square root : 2.23607
Destructor called.
Destructor called.
Destructor called.
*/