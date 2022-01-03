#include <iostream>

using namespace std;

class Point
{
	int _x, _y;
	public:
		Point(int x, int y):
			_x(x),
			_y(y)
		{
			cout << "Point Ctor: ";
			print(); cout << endl; 
		}
		~Point(){
			cout << "Point Dtor";
			print(); cout << endl;
		}

		void print(){
			cout << "( " << _x << ", " << _y << " )";
		}
};

class Rect
{
	Point _TL;
	Point _BR;
	public:
		Rect(int tx, int ty, int bx, int by):
			_TL(tx, ty),
			_BR(bx, by)
		{
			cout << "Rect Ctor ";
			print(); cout << endl;
		}
		~Rect(){
			cout << "Rect Dtor ";
			print(); cout << endl;
		}

		void print(){
			cout << "[";
			_TL.print();
			cout << " ";
			_BR.print();
			cout << "]";
		}
};

int main(int argc, char const *argv[])
{
	Rect r(0, 2, 5, 7);
	cout << endl; r.print(); cout << endl;
	cout << endl;
	return 0;
}

/*
Point Ctor: ( 0, 2 )
Point Ctor: ( 5, 7 )
Rect Ctor [( 0, 2 ) ( 5, 7 )]

[( 0, 2 ) ( 5, 7 )]

Rect Dtor [( 0, 2 ) ( 5, 7 )]
Point Dtor( 5, 7 )
Point Dtor( 0, 2 )
*/