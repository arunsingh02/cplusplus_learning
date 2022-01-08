#include <iostream>

using namespace std;

class String {
public  :
  char *str_;
  int len_;

public:
  String (char *s):
    str_(strdup(s)), len_(strlen(s))
    {
      cout << "String Ctor Called \n"; print(); cout << endl;
    }
  String(const String& a):
    str_(strdup(a.str_)), len_(a.len_)
    {
      cout << "String Copy Constructor Called." << endl;
    }
  // Copy Assignment Operator
  String& operator=(const String& b) // return value is String& for chain assignment
  {
    if (this != &b){ // safe code for self copy like s1 = s1.
      free(str_);
      // str_ = strdup(b.str_);
      str_ = strdup("Ravi Singh");
      len_ = b.len_;
      cout << "Copy assignment operator \n";
      print();
    }
    return *this; // required
  }

  virtual ~String (){
    free(str_);
    cout << "String Dtor Called" << endl;
  }
  void print(){
    cout << "String is " << str_ << " and its length is " << len_ << "." << endl;
  }
};

void str_to_caps(String str){
  for (int i=0; i< str.len_; ++i) str.str_[i] = toupper(str.str_[i]);
  cout << "Str to upper : "; str.print(); cout << endl;
}

int main(int argc, char const *argv[]) {
  String s = "Arun Singh"; // ctor
  str_to_caps(s); // copy Ctor
  // S1 is new object and copy from existing obj s.
  String s1(s);
  String s2(s1);
  // Both object already exist
  s1 = s; // copy assignment operator (No return type in operator assignment will be fine)
  s = s1 = s2; // copy assignment chain s1 = ( s1 = s2 )
  cout << "s1 object : "; s1.print();
  return 0;
}

/*
String Ctor Called
String is Arun Singh and its length is 10.

String Copy Constructor Called.
Str to upper : String is ARUN SINGH and its length is 10.

String Dtor Called
String Copy Constructor Called.
String Copy Constructor Called.
Copy assignment operator
String is Ravi Singh and its length is 10.
Copy assignment operator
String is Ravi Singh and its length is 10.
Copy assignment operator
String is Ravi Singh and its length is 10.
s1 object : String is Ravi Singh and its length is 10.
String Dtor Called
String Dtor Called
String Dtor Called
*/
