// Pure virtual function called abstract base class

#include <iostream>
using namespace std;

class Animal {
public:
  virtual void walk() = 0;
  // Always be public
  virtual void talk() = 0; // Pure virtual function
};

// outline the function body
void Animal::walk(){
  cout << "Walk mode : " << endl;
}

class Dog: public Animal {
public:
  void talk() { // should be define pure virtual function
    cout << "Bhwo Bhwoo" << endl;
  }
};

class Paverian: public Dog {
public:
  void talk() { // should be define pure virtual function
    cout << "Bhee Bhee" << endl;
  }

  void walk() { // should be define pure virtual function
    cout << "slowly" << endl;
  }
};

int main(int argc, char const *argv[]) {
  // Animal a; We can't intatiate the abstract base class
  Paverian p1; // inherit class A and define the pure virtual function
  p1.walk();
  p1.talk();
  return 0;
}
