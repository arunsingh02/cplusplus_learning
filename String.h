#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#include <string>

using namespace std;

class String {
private:
  char *str_;
  int len_;
public:
  String(const char *s):
    str_(strdup(s)), len_(strlen(s))
    {
      cout << "String Ctor : ";
      print();
      cout << endl;
    }
  // Not required in this case.
  /*
  String(const String& a):
    str_(strdup(a.str_)), len_(a.len_)
    {}
  String& operator=(const String& b)
  {
    if (this != &b){
      free(str_);
      str_ = strdup(b.str_);
      len_ = strlen(str_);
      return *this;
    }
  }
  */
  void print(){
    cout << "String = " << str_ << " , length = " << len_ << endl;
  }
  void getName(){
    cout << str_;
  }
};

#endif
