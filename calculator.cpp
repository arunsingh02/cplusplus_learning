#include <iostream>
using namespace std;

int add(int x, int y){
	return x + y;
}

int sub(int x, int y){
	return x - y;
}

int mul(int x, int y){
	return x * y;
}

int divide(int x, int y){
	return x / y;
}

int main(){
	int x, y;
	char z;
	cout << "Enter the nums: ";
	cin >> x >> y;
	cout << "Enter operator: ";
	cin >> z;

	if (z == '+'){
		cout << x << z << y << " = " << add(x, y) << endl;
	}
	else if (z == '-'){
		cout << x << z << y << " = " << sub(x, y) << endl;
	}
	else if (z == '*'){
		cout << x << z << y << " = " << mul(x, y) << endl;
	}
	else if (z == '/'){
		cout << x << z << y << " = " << divide(x, y) << endl;
	}
	else{
		cout << "Please provide +, -, * and / operator for successful operation" << endl;
	}
}