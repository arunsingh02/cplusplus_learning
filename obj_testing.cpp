#include <iostream>

using namespace std;

class Complex {
private:
  double re_, im_;

public:
  Complex (double re, double im):
    re_(re), im_(im)
    {
      cout << "Ctor Called." << endl;
    }

  // Complex(const Complex& c): // We can't change the state of Complex c
  //   re_(c.re_), im_(c.im_)
  //   {
  //     cout << "Copy Ctor called." << endl;
  //   }

  Complex(Complex& c): // We can change the state of Complex c
    re_(c.re_), im_(c.im_)
    {
      c.re_ = 10;
      cout << "id : " << &c << endl;
      cout << "This is Correct because const not used.." << c.re_ << endl;
    }

  // Not possible. It will go in loop.
  // Complex(Complex c): // Call by value
  //   c.im_ = 20;
  //   {cout << "Not Correct" << endl;}

  virtual ~Complex (){
    cout << "Dtor Called" << endl;
  }

  void print(){
    cout << "|" << re_ << "+j" << im_ << "|" << endl;
  }
};

void display(Complex copy_c){ //Complex& (ref) will not call the cctor (duplicate obj)
  cout << "Different copy ctor id : " << &copy_c << " : ";
  copy_c.print();
}

int main(int argc, char const *argv[]) {
  Complex c1(1.2, 3.2);
  cout << "c1 obj : " << &c1 << endl;
  display(c1);
  c1.print();
  return 0;
}

// https://www.educative.io/edpresso/differences-between-pointers-and-references-in-cpp
/*
Ctor Called.
c1 obj : 0x7ffee58477a8
id : 0x7ffee58477a8
This is Correct because const not used..10
Different copy ctor id : 0x7ffee5847780 : |1.2+j3.2|
Dtor Called
|10+j3.2|
Dtor Called
*/
