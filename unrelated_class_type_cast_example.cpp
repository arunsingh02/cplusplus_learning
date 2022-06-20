#include <iostream>
using namespace std;

// inheritence example

class A {
public:
  int i = 1;
};

class B: public A {
public:
  double d = 10.2;
};

// Normal class example

class C {
public:
  int i = 2;
};

class D {
public:
  double d = 20.2;
};

int main(int argc, char const *argv[]) {
  A a;
  B b;

  cout << "A data : " << a.i << endl;
  cout << "B data inheritence : " << b.i << endl;
  cout << "B data : " << b.d << endl;

  a = b; // UPCASTING
  // b = a;  error: no viable overloaded '='   DOWNCASTING

  a = (A)b; // Only working in inheritence model
  // b = (B)a;  error: no matching conversion for C-style cast from 'A' to 'B'

  A *p = &a;
  B *q = &b;

  p = (A*)&b;

  cout << "A poiter data : " << p->i << endl;

  C c;
  D d;

  C *r = &c;
  D *s = &d;

  // c = (C)d;  error: no matching conversion for C-style cast from 'D' to 'C'

  // c = d;     error: no viable overloaded '='

  r = (C*)&s;   // Forced casting on Pointer will be very Dangerous
  s = (D*)&r;

  cout << "C data : " << r->i << endl;
  cout << "D data : " << s->d << endl;
  return 0;
}

/*
A data : 1
B data inheritence : 1
B data : 10.2
A poiter data : 1
C data : -1302628808   // Garbage value
D data : 6.95159e-310  // Garbage value
*/
