#include <iostream>

using namespace std;

class MyClass {
private:
  int privateNo;

public:
  int publicNo;
  MyClass (int p1, int p2):
    privateNo(p1), publicNo(p2)
    {}
  virtual ~MyClass (){}

  int getmember() const { // constant member function
    return privateNo;
  }

  void setMember(int n){
    publicNo = n;
  }

  // Using keyword const between the function header and the body.
  void print() const { // constant member function
    cout << "Private num : " << privateNo << endl;
    cout << "Public num : " << publicNo << endl;
  }
};

int main(int argc, char const *argv[]) {
  // const MyClass * const this;
  // instead of
  // MyClass * const this; (Const pointer to non-constant object creation)
  const MyClass c1(11, 22); // Const pointer to constant object creation
  cout << c1.getmember() << endl;
  // error: cannot assign to variable 'c1' with const-qualified type 'const MyClass'
  // c1.publicNo = 33;
  // error: 'this' argument to member function 'setMember' has type 'const MyClass',
  // but function is not marked const
  // c1.setMember(44);
  c1.print(); // const data method calling.
  return 0;
}
