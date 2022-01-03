#include <iostream>
#include <cstring>
using namespace std;

typedef struct _String
{
	char *str;
} String;

String operator+(const String& s1, const String& s2){
	String s;
	s.str = (char *) malloc(strlen(s1.str) + strlen(s2.str) + 1);
	strcpy(s.str, s1.str);
	strcat(s.str, s2.str);
	return s;
}

int main(int argc, char const *argv[])
{
	String fname, lname, name;
	fname.str = strdup("Arun ");
	lname.str = strdup("Singh");
	name = fname + lname;
	cout << "First name : " << fname.str << endl;
	cout << "Last name  : " << lname.str << endl;
	cout << "Full name  : " << name.str << endl;
	return 0;
}

/*
First name : Arun 
Last name  : Singh
Full name  : Arun Singh
*/