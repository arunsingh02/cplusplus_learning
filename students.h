#ifndef _STUDENTS_H
#define	_STUDENTS_H
#include <iostream>

using namespace std;

class studentInfo{
public:
  typedef enum GENDER {male = 0, female};
  studentInfo(char *n, GENDER g):
    name(strcpy(new char[strlen(n)+1], n)), gender(g) {}

  void setRoll(int r){
    roll = r;
  }

  GENDER getGender(){
    return gender;
  }

  friend ostream& operator<<(ostream& stream, const studentInfo& st){
    cout << ((st.gender == studentInfo::male) ? "Male " : "Female ")
         << st.name << " " << st.roll << endl;
    return stream;
  }

private:
  char *name;
  GENDER gender;
  int roll;
};

class studentRegister{
private:
  studentInfo **record; // List of students
  int nStudents;
public:
  studentRegister(int size):
    record(new studentInfo*[size]), nStudents(0) {}

  void add(studentInfo* s){
    record[nStudents] = s;
    s->setRoll(++nStudents);
  }

  studentInfo *getStudent(int r){
    return (r == nStudents + 1) ? 0 : record[r - 1];
  }

  void print(){
    cout << "Total number of students: " << nStudents << endl;
  }

};

#endif /*_STUDENTS_H*/
