#include "students.h"

extern studentRegister *reg;

namespace MALE{
  void maleStudent() {
    cout << "MALE STUDENTS : " << endl;
    int r = 1;
    studentInfo *s;
    while (s = reg->getStudent(r++)){
      if (s->getGender() == studentInfo::male)
        cout << *s;
    }
    cout << endl;
  }
}

namespace FEMALE{
  void femaleStudent() {
    cout << "FEMALE STUDENTS : " << endl;
    int r = 1;
    studentInfo *s;
    while (s = reg->getStudent(r++)){
      if (s->getGender() == studentInfo::female)
        cout << *s;
    }
    cout << endl;
  }
}

studentRegister *reg = new studentRegister(1000);

int main(int argc, char const *argv[]) {
  studentInfo s1("Arun", studentInfo::male);
  reg->add(&s1);
  studentInfo s2("Ragini", studentInfo::female);
  reg->add(&s2);
  studentInfo s3("Ravi", studentInfo::male);
  reg->add(&s3);
  studentInfo s4("Jyoti", studentInfo::female);
  reg->add(&s4);
  studentInfo s5("Priyanka", studentInfo::female);
  reg->add(&s5);

  reg->print();

  MALE::maleStudent();
  FEMALE::femaleStudent();

  return 0;
}

/*
Total number of students: 5
MALE STUDENTS :
Male Arun 1
Male Ravi 3

FEMALE STUDENTS :
Female Ragini 2
Female Jyoti 4
Female Priyanka 5

*/
