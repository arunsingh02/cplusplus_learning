#include <iostream>
#include <cmath>

using namespace std;

class Complex {
  double re_, im_;

  public:
    Complex(double re, double im):
      re_(re), im_(im)
      {
        cout << "Standard Ctor : ";
        print();
      }
    Complex(const Complex& c): // Copy Constructor
      re_(c.re_), im_(c.im_)
      {
        cout << "Copy Ctor: ";
        print();
      }
    ~Complex(){
      cout << "Standard Dtor : ";
      print();
    }

    void print(){
      cout << "|" << re_ << "+j" << im_ << "| = " << norm() << endl;
    }

    double norm(){
      return sqrt(re_*re_ + im_*im_);
    }
};

void display(Complex c_obj){
  cout << "Copy Ctor test :";
  c_obj.print();
}

int main(int argc, char const *argv[]) {
  Complex c(4.2, 5.3);
  display(c);
  return 0;
}

/*
Standard Ctor : |4.2+j5.3| = 6.7624
Copy Ctor: |4.2+j5.3| = 6.7624
Copy Ctor test :|4.2+j5.3| = 6.7624
Standard Dtor : |4.2+j5.3| = 6.7624
Standard Dtor : |4.2+j5.3| = 6.7624
*/
