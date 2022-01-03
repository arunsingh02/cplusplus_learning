#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	char str[10] = "ABCDEF";
	stack<char> s;
	for (int i=0; i < strlen(str); i++)
		s.push(str[i]);
	cout << "Reverse string of " << str << " is : ";
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}

// Reverse string of ABCDEF is : FEDCBA