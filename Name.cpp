#include "String.h"

class Name {
private:
  String firstname, lastname;

public:
  Name (const char *f, const char *l):
    firstname(f), lastname(l){}
  virtual ~Name (){}
  void print(){
    cout << "My Name is ";
    firstname.getName(); cout << " ";
    lastname.getName(); cout  << "." << endl;
  }
};

int main(int argc, char const *argv[]) {
  Name name("Arun", "Singh");
  name.print();
  return 0;
}

/*
String Ctor : String = Arun , length = 4

String Ctor : String = Singh , length = 5

My Name is Arun Singh.
*/
