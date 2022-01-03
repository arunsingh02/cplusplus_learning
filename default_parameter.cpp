#include <iostream>
using namespace std;

double IdentifyFunction(int a, double d = 10, bool flag = true){
	if (flag) return (a * d * d);
	else return (a * d * d * d);
}

int main(int argc, char const *argv[])
{
	int a = 5;
	double d = 2.3;
	cout << "Checking the results -> \n";
	cout << "With single arg : " << IdentifyFunction(a) << endl;
	cout << "With all arg : " << IdentifyFunction(a, d) << endl;
	cout << "Without arg : " << IdentifyFunction(a, d, false) << endl;
	// cout << "Without arg : " << IdentifyFunction() << endl;   // Error
	// cout << "Without arg : " << IdentifyFunction(a, true) << endl;   // Error
	// cout << "Without arg : " << IdentifyFunction(b) << endl;   // Error
	return 0;
}

/*
Checking the results -> 
With single arg : 500
With all arg : 26.45
Without arg : 60.835
*/
