#include <iostream>

using namespace std;

class Stack
{// private
	char *_data; // dynamic mem
	int _top;
	public:
		// Constructor
		/*
		Stack(size_t = 10):
			_data(new cha[data_len])
			...
		*/
		Stack():
			_data(new char[10]),
			_top(-1)
		{
			cout << "Constructor called." << endl;
		}

		// De-constructor
		~Stack(){
			cout << "De-Constructor called." << endl;
			delete [] _data;
		}

		int empty(){return (_top == -1);}

		void push(char x){ _data[++_top] = x; }

		void pop(){ _top--; }

		char top(){ return _data[_top]; }
	
};

int main(int argc, char const *argv[])
{
	char data[] = "ABCDE";

	// char *data = new char[5];
	// data = "ABCDE"; // Warning

	Stack s;
	// Stack s(strlen(data));

	cout << "Real string is : " << data << endl;
	for (int i = 0; i < 5; ++i){
		 s.push(data[i]);
	}
	cout << "Reverse string is : ";
	while(!s.empty()){
		cout << s.top();
		s.pop();
	} 
	cout << endl;
	return 0;
}

/*
Constructor called.
Real string is : ABCDE
Reverse string is : EDCBA
De-Constructor called.
*/