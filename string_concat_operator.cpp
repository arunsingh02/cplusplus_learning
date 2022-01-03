#include <iostream>
#include <cstring>
using namespace std;

typedef struct _String
{
	char *str;
} String;


// operator function
// a + b  >> operator+(a, b)
// c = a + b >> operator=(c, operator+(a, b))
String operator+(const String& s1, const String& s2){
	String s;
	// s.str = (char *) malloc(strlen(s1.str) * sizeof(char) + strlen(s2.str) * sizeof(char) + 1);
	s.str = new char; //Also correct
	cout << "Size od s.str : " << sizeof(s.str) << endl;
	strcpy(s.str, s1.str);
	strcat(s.str, s2.str);
	return s;
}

int main(int argc, char const *argv[])
{
	String fname, lname, name;
	fname.str = strdup("Arun ");
	lname.str = strdup("Singh");
	name = fname + lname; // Calling operator function (Overload operator +)
	// cout << "Size of double and float : " << sizeof(double) << " : " << sizeof(float) << endl;

	cout << "First name : " << fname.str << endl;
	cout << "Last name  : " << lname.str << endl;
	cout << "Full name  : " << name.str << endl;
	delete name.str; // deleting the occupied dynamic memory
	return 0;
}

/*
First name : Arun 
Last name  : Singh
Full name  : Arun Singh
*/