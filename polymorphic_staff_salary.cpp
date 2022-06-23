#include <iostream>
#include <string>
using namespace std;

class Engineer {
protected:
  string name_;
public:
  Engineer (const string& name): name_(name) {}
  virtual void salary_processing(){ // Dynamic Binding (run time)
    cout << name_ << " : Processing Engineer salary" << endl;
  }

  virtual ~Engineer() {};
};

class Manager: public Engineer {
Engineer *_reports[10];
public:
  Manager (const string &name): Engineer(name) {}
  void salary_processing(){
    cout << name_ << " : Processing Manager salary" << endl;
  }
};

class Director: public Manager {
Manager *_reports[10];
public:
  Director (const string &name): Manager(name) {}
  void salary_processing(){
    cout << name_ << " : Processing Director salary" << endl;
  }
};

int main(int argc, char const *argv[]) {
  Engineer e1("Arun"), e2("Ranjan"), e3("Sahana");
  Manager m1("Praveen"), m2("Ganesh");
  Director d1("Rao");

  Engineer *obj[] = {&e1, &e2, &e3, &m1, &m2, &d1};

  for (int i = 0; i < (sizeof(obj) / sizeof(Engineer*)) ; ++i)
    obj[i]->salary_processing();
  return 0;
}


/*
Arun : Processing Engineer salary
Ranjan : Processing Engineer salary
Sahana : Processing Engineer salary
Praveen : Processing Manager salary
Ganesh : Processing Manager salary
Rao : Processing Director salary
*/
