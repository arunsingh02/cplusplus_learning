// TODO Need some more knowledge

#include <iostream>
using namespace std;

typedef struct {
	int square_matrix[3][3];
} Matrix;

typedef struct {
	int row_matrix[3][1];
} VectorRow;

typedef struct {
	int col_matrix[1][3];
} VectorCol;

typedef struct {
	int i;
	int k;
} Data;

// testing
void Multiply(const Matrix& a, const VectorCol& b, Data& c){
	c.i = a.square_matrix[0][1];
	c.k = b.col_matrix[2][0];
	cout << "A : " << c.i << " " << c.k << endl;
}

// testing
void Multiply(const Data& x, const Data& y, Data& z){
	z.i = x.i * y.i;
	z.k = x.k + y.k;
	cout << "Data d3 ->> \n" << "i : " << z.i << " k : " << z.k << endl;
	// return (y.i - x.k);
}

int main(int argc, char const *argv[])
{
	int i, j;
	Matrix m1, m2;
	VectorCol vc, rcv;
	VectorRow vr, rrv;
	Data d1, d2, d3;

	d1.i = 10;
	d1.k = 20;

	d2.i = 30;
	d2.k = 40;

	Multiply(d1, d2, d3); // static polymorphism function call

	// Taking user inputs
	cout << "Enter the matrix elements : ";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> m1.square_matrix[i][j];
	cout << "Enter the vector col elements : ";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            cin >> vc.col_matrix[i][j];
	Multiply(m1, vc, d3); // function overloading function call
	return 0;
}

/*
Data d3 ->> 
i : 300 k : 60
10
Enter the matrix elements : 1 2 3 4 5 6 7 8 9 
Enter the vector col elements : 4 5 6
A : 2 6
*/
