#include <iostream>
using namespace std;

// Class 
class Complex {
	public: // Declaring access specifier (Default is private)
		double re_, im_; // data members

		double re_getter(){ // methods
			return re_; 
		}

		void re_setter(double re){
			re_ = re;
		}

		double im_getter(){
			return im_; 
		}

		void im_setter(double im){
			im_ = im;
		}
};

int main(int argc, char const *argv[])
{
	Complex c = {3.4, 5.6}; // Object declearation and initialization
	c.re_setter(c.re_);
	cout << "REAl : " << c.re_getter() << endl;
	c.im_setter(c.im_);
	cout << "IMEGINARY : " << c.im_getter() << endl;
	c.im_setter(12.4);
	cout << "State change for Img : " << c.im_getter() << endl;
	return 0;
}

/*
REAl : 3.4
IMEGINARY : 5.6
State change for Img : 12.4
./cl  0.00s user 0.00s system 45% cpu 0.005 total
*/