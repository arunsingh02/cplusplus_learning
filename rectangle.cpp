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
		// Point copy constructor
		Point(const Point& p):
		_x(p._x), _y(p._y)
		{
			cout << "Point copy ctor" << endl;
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

		Rect(const Point& p1, const Point& p2):
			_TL(p1), _BR(p2)
			{
				cout << "point Rect taken ctor" << endl;
			}
		// Rect copy constructor
		Rect(const Rect& r):
			_TL(r._TL),
			_BR(r._BR)
			{
				cout << "Rect copy ctor" << endl;
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

	Rect r2(Point(2, 3), Point(4, 5));
	cout << endl; r2.print(); cout << endl;
	cout << endl;

	Rect r3(r); // default copy ctor called.
	cout << endl; r3.print(); cout << endl;
	cout << endl;

	return 0;
}

/*
Point Ctor: ( 0, 2 )
Point Ctor: ( 5, 7 )
Rect Ctor [( 0, 2 ) ( 5, 7 )]

[( 0, 2 ) ( 5, 7 )]

Point Ctor: ( 2, 3 )
Point Ctor: ( 4, 5 )
Point copy ctor
Point copy ctor
point Rect taken ctor
Point Dtor( 4, 5 )
Point Dtor( 2, 3 )

[( 2, 3 ) ( 4, 5 )]

Point copy ctor
Point copy ctor
Rect copy ctor

[( 0, 2 ) ( 5, 7 )]

Rect Dtor [( 0, 2 ) ( 5, 7 )]
Point Dtor( 5, 7 )
Point Dtor( 0, 2 )
Rect Dtor [( 2, 3 ) ( 4, 5 )]
Point Dtor( 4, 5 )
Point Dtor( 2, 3 )
Rect Dtor [( 0, 2 ) ( 5, 7 )]
Point Dtor( 5, 7 )
Point Dtor( 0, 2 )
*/
