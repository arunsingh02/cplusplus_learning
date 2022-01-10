#include <iostream>

using namespace std;

// Static Member Function Printer
class SMFPrinter {
private:
  int _pageNo;
  static int _noPrinterTray; // static data member (scope : class)
  static int _noJobs;

public:
  SMFPrinter (int pn): _pageNo(pn){
    ++_noJobs;
    _noPrinterTray -= pn;
  }
  virtual ~SMFPrinter (){
    --_noJobs;
    cout << "Remaining Job " << _noJobs << endl;
  }

  static int getter(){
    return _noJobs;
  }

  static void setter(int n){
    _noPrinterTray = n;
  }

  void printing(){
    cout << "Total Running Jobs : " << _noJobs << endl;
    cout << "Remaining Printer Tray : " << _noPrinterTray << endl;
  }
};

// Static Data Member Printer
class SDMPrinter {
private:
  int _pageNo;

public:
  static int _noPrinterTray; // static data member (scope : class)
  static int _noJobs;
  SDMPrinter (int pn): _pageNo(pn){
    ++_noJobs;
    _noPrinterTray -= pn;
  }
  virtual ~SDMPrinter (){
    --_noJobs;
    cout << "Remaining Job " << _noJobs << endl;
  }

  void get_job(){
    cout << "Total Running Jobs : " << _noJobs << endl;
    cout << "Remaining Printer Tray : " << _noPrinterTray << endl;
  }

  void printing(){
    cout << "Printer is running." << endl;
  }
};

// Static data member initialize.
int SDMPrinter::_noJobs = 0; // static data member definition and initialize.
int SDMPrinter::_noPrinterTray = 500; // Required before obj creation

int SMFPrinter::_noJobs = 0; // static data member definition and initialize.
int SMFPrinter::_noPrinterTray = 500; // Required before obj creation

// Running Application
int main(int argc, char const *argv[]) {
  cout << endl;
  cout << " :: Static data member output :: " << endl;
  cout << endl;
  {
    SDMPrinter p1(10);
    p1.get_job();
    SDMPrinter p2(100);
    p2.get_job();

    SDMPrinter p3(70);
    p3.get_job();
    SDMPrinter::_noPrinterTray += 300;
    SDMPrinter p4(30);
    p4.get_job();
  }

  cout << endl;
  cout << " :: Static member function output :: " << endl;
  cout << endl;

  {
    SMFPrinter fp1(22);
    cout << "Jobs : " << SMFPrinter::getter() << endl;
    SMFPrinter::setter(200);
    SMFPrinter fp2(120);
    cout << "Jobs : " << SMFPrinter::getter() << endl;
    fp2.printing();
  }
  return 0;
}

/*

 :: Static data member output ::

Total Running Jobs : 1
Remaining Printer Tray : 490
Total Running Jobs : 2
Remaining Printer Tray : 390
Total Running Jobs : 3
Remaining Printer Tray : 320
Total Running Jobs : 4
Remaining Printer Tray : 590
Remaining Job 3
Remaining Job 2
Remaining Job 1
Remaining Job 0

 :: Static member function output ::

Jobs : 1
Jobs : 2
Total Running Jobs : 2
Remaining Printer Tray : 80
Remaining Job 1
Remaining Job 0

*/
