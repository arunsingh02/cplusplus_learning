#include <iostream>
using namespace std;

// Global variable (scope)
int data = 0;

namespace App1 {
  int data = 1;
} /* App1 */

namespace App2 {
  int data = 2;
} /* App2 */

int main(int argc, char const *argv[]) {
  cout << "global data : " << ::data << endl;
  cout << "namespace 1 data : " << App1::data << endl;
  App2::data = 100;
  cout << "namespace 2 data : " << App2::data << endl;
  return 0;
}

/*
global data : 0
namespace 1 data : 1
namespace 2 data : 100
*/
