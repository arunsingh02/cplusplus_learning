#include <iostream>

using namespace std;

// Singelton Class
class Printer {
private:
  bool blackAndWhite_, doubleSide_;
  // Private Ctor to make const object.
  Printer(bool bw = true, bool ds = false): blackAndWhite_(bw), doubleSide_(ds){
    cout << "Private Ctor" << endl;
  }
  // static data member
  static Printer *myPrinter;

public:
  virtual ~Printer (){}
  // Checking the object create or not. Object will create only first time.
  static const Printer& printer(bool bw=true, bool ds=false){
    if (!myPrinter)
      myPrinter = new Printer(bw, ds);
    return *myPrinter;
  }

  void print(int np) const {
    cout << "Printing " << np << " pages." << endl;
  }
};

Printer *Printer::myPrinter = 0;

int main(int argc, char const *argv[]) {
  Printer::printer(true, true).print(10);
  Printer::printer().print(100);
  Printer::printer().~Printer();
  return 0;
}

/*
Private Ctor
Printing 10 pages.
Printing 100 pages.
*/
