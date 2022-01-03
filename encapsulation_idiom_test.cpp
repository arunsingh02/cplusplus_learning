#include <iostream>
using namespace std;

// Class 
class Idiom
{ // private (default)
	int readWrite_;
	int readOnly_;
	int writeOnly_;
	int invisible_;

	public:
		// Any one can read and write
		int getReadWrite(){ return readWrite_; };
		void setReadWrite(int v){ readWrite_ = v; };

		// Only read no write
		int getReadOnly(){ return readOnly_; };

		// only write no read
		void setWriteOnly(int v){ writeOnly_ = v; };

		// no method for invisible
	
};

int main(int argc, char const *argv[])
{
	Idiom id;
	id.setReadWrite(123);
	cout << id.getReadWrite() << endl;
	cout << id.getReadOnly() << endl;
	return 0;
}

/*
123
0
*/