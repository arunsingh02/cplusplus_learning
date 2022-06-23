#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
  string name_;
  vector<Employee*> reports_;
public:
  virtual void salary_processing() = 0; // Pure Polymorphic (abstract base class)

  static vector<Employee*> staffs;
  void addStaff(Employee* e){
    staffs.push_back(e);
  }

  virtual ~Employee () {};
};


class Engineer: public Employee {
public:
  Engineer (const string& name) {
    name_ = name;
    addStaff(this);
  }
  virtual void salary_processing(){ // Dynamic Binding (run time)
    cout << name_ << " : Processing Engineer salary" << endl;
  }
};

class Manager: public Engineer {
Engineer *reports_[10];
public:
  Manager (const string &name): Engineer(name) {}
  void salary_processing(){
    cout << name_ << " : Processing Manager salary" << endl;
  }
};

class Director: public Manager {
Manager *reports_[10];
public:
  Director (const string &name): Manager(name) {}
  void salary_processing(){
    cout << name_ << " : Processing Director salary" << endl;
  }
};

class Sales: public Employee {
public:
  Sales (const string& name) {
    name_ = name;
    addStaff(this);
  }
  void salary_processing(){
    cout << name_ << " : Processing Sales Executive salary" << endl;
  }
};

vector<Employee*> Employee::staffs;

int main(int argc, char const *argv[]) {
  Engineer e1("Arun"), e2("Ranjan"), e3("Sahana");
  Manager m1("Praveen"), m2("Ganesh");
  Director d1("Rao");
  Sales s1("Prateek"), s2("Furqan");

  vector<Employee*>::const_iterator it;

  for (it = Employee::staffs.begin(); it < Employee::staffs.end(); ++it)
    (*it)->salary_processing();
  return 0;
}


/*
Arun : Processing Engineer salary
Ranjan : Processing Engineer salary
Ganesh : Processing Manager salary
Rao : Processing Director salary
Prateek : Processing Sales Executive salary
Furqan : Processing Sales Executive salary
Sahana : Processing Engineer salary
Praveen : Processing Manager salary
*/
