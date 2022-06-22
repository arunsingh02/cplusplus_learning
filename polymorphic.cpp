// If any funtion is virtual type by definition or inheritence, called polymorphic type.

#include <iostream>
using namespace std;

class A {
public:
  void x() {
    cout << "A::x()" << endl;
  }
  virtual void y() {
    cout << "A::y()" << endl;
  }
  void z() {
    cout << "A::z()" << endl;
  }
};

class B: public A {
public:
  void x() { // Overriding
    cout << "B::x()" << endl;
  }
  void y() { // By default virtual (we can't revert to non-virtual)
    cout << "B::y()" << endl;
  }
  virtual void z() { // Making virtual (we can change into virtual)
    cout << "B::z()" << endl;
  }
};

class C: public B {
public:
  void x() { // Overriding
    cout << "C::x()" << endl;
  }
  void y() { // By default virtual
    cout << "C::y()" << endl;
  }
  void z() { // By default virtual
    cout << "C::z()" << endl;
  }
};

int main(int argc, char const *argv[]) {
  B *b = new C;
  A *a = b;

  a->x();
  a->y(); // dynamic
  a->z();

  b->x();
  b->y(); //dynamic
  b->z(); //dynamic
  return 0;
}


/*
A::x()
C::y()   // Dynamic binding (Cheking the actula object of a which is C here)
A::z()
B::x()
C::y()   // Dynamic binding (Cheking the actula object of b which is C here)
C::z()   // Dynamic binding (Cheking the actula object of b which is C here)
*/
