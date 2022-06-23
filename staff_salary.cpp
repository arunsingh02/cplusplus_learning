#include <iostream>
#include <string>
using namespace std;

enum E_TYPE {ER, MGR, DIR};

class Engineer {
protected:
  string name_;
  E_TYPE type_;
public:
  Engineer (const string& name, E_TYPE e = ER):
  name_(name), type_(e) {}
  E_TYPE getType(){
    return type_;
  }

  void salary_processing(){
    cout << name_ << " : Processing Engineer salary" << endl;
  }

  virtual ~Engineer() {};
};

class Manager: public Engineer {
Engineer *_reports[10];
public:
  Manager (const string &name, E_TYPE e = MGR):
  Engineer(name, e) {}
  void salary_processing(){
    cout << name_ << " : Processing Manager salary" << endl;
  }
};

class Director: public Manager {
Manager *_reports[10];
public:
  Director (const string &name, E_TYPE e = DIR):
  Manager(name, e) {}
  void salary_processing(){
    cout << name_ << " : Processing Director salary" << endl;
  }
};

int main(int argc, char const *argv[]) {
  Engineer e1("Arun"), e2("Ranjan"), e3("Sahana");
  Manager m1("Praveen"), m2("Ganesh");
  Director d1("Rao");

  Engineer *obj[] = {&e1, &e2, &e3, &m1, &m2, &d1};

  cout << "Size of obj : " << sizeof(obj) << endl;
  cout << "Size of Engineer : " << sizeof(Engineer*) << endl;
  int k = sizeof(obj) / sizeof(Engineer*);
  cout << "Size of k : " << k << endl;
  cout << "-----------------------------------" << endl;
  for (int i = (sizeof(obj) / sizeof(Engineer*)) - 1; i > -1 ; --i){
    E_TYPE eng_type = obj[i]->getType();
    if (eng_type == ER)
      obj[i]->salary_processing();
    else if (eng_type == MGR)
      ((Manager *)obj[i])->salary_processing(); // Down casting Risky
    else if (eng_type == DIR)
      ((Director *)obj[i])->salary_processing();
    else
      cout << "Invalid Type!!" << endl;
  }
  return 0;
}


/*
Size of obj : 48
Size of Engineer : 8
Size of k : 6
-----------------------------------
Rao : Processing Director salary
Ganesh : Processing Manager salary
Praveen : Processing Manager salary
Sahana : Processing Engineer salary
Ranjan : Processing Engineer salary
Arun : Processing Engineer salary
*/
