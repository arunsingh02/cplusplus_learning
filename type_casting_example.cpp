#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int i = 10;
  double d = 12.34;
  double result = d / i;
  cout << "Implicit type casting Result : " << result << endl;

  d = i;
  cout << "Implicit : " << d << '\n';

  double dd = 13.73;
  i = dd;
  cout << "Implicit : " << i << '\n';

  dd = (double)i;
  cout << "Explicit : " << d << '\n';

  double ddd = 14.84;
  i = (int)ddd;
  cout << "Explicit : " << i << '\n';

  // double *p = &ddd;

  // Implicit not allowed
  // i = p;   error: assigning to 'int' from incompatible type 'double *'

  // Explicit will work sf_inplace
  // double dddd = 10.22;
  // dddd = (double)p;    error: C-style cast from 'double *' to 'double' is not allowed
  //
  // cout << "Pointer Explicit : " << dddd << endl;


  // POINTERS CHECK
  int a = 1, *p = &a;
  double b = 2.2, *q = &b;
  void *r;

  // p = q;  error: assigning to 'int *' from incompatible type 'double *'
  // q = p;  error: assigning to 'double *' from incompatible type 'int *'

  // p = (double*)q;   error: assigning to 'int *' from incompatible type 'double *'

  q = (double*)p;

  p = (int*)q;

  r = (double*)q;

  // p = r;  error: assigning to 'int *' from incompatible type 'void *'

  p = (int*)r;

  return 0;
}


/*
Implicit type casting Result : 1.234
Implicit : 10
Implicit : 13
Explicit : 10
Explicit : 14
*/
