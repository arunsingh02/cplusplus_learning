#include <iostream>
using namespace std;

class A {
public:
  void static_func() {
    cout << "A::static_func()" << endl;
  }
  virtual void dynamic_func() {
    cout << "A::dynamic_func()" << endl;
  }
};

class B: public A {
public:
  void static_func() { // Overriding
    cout << "B::static_func()" << endl;
  }
  void static_func(int i) { // Overloading
    cout << "B::static_func(int) : " << i << endl;
  }
  virtual void dynamic_func() { // Overriding
    cout << "B::dynamic_func()" << endl;
  }
};


int main(int argc, char const *argv[]) {
  A a;
  B b;

  a.static_func();
  b.static_func();
  b.static_func(10);

  A *p = &a;
  A *q = &b; // UPCAST

  A &ra = a;
  A &rb = b; // UPCAST

  p->static_func();
  p->dynamic_func();
  q->static_func();
  q->dynamic_func();
  // q->static_func(20);  error: too many arguments to function call, expected 0, have 1

  ra.static_func();
  ra.dynamic_func();
  rb.static_func();
  rb.dynamic_func();
  // rb.static_func(30);  error: too many arguments to function call, expected 0, have 1
  return 0;
}


/*
A::static_func()   --static binding
B::static_func()
B::static_func(int) : 10
A::static_func()
A::dynamic_func()   --dynamic binding (virtual function)
A::static_func()
B::dynamic_func()
A::static_func()
A::dynamic_func()
A::static_func()
B::dynamic_func()
*/
