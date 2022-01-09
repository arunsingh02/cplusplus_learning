#include <iostream>
#include <string>

using namespace std;

class CreditCard {
private:
  const size_t cardNo;
  char *name;
  int pin;
  const int cvv;

public:
  char *issueMonth, *expiryMonth, *addr;

  CreditCard (size_t cn, char *n, char *im, char *em, char *add, int cv):
    cardNo(cn), name(strdup(n)), issueMonth(strdup(im)), expiryMonth(strdup(em)),
    addr(strdup(add)), cvv(cv)
    {}

  virtual ~CreditCard (){
    free(name);
    free(addr);
  }

  void get_card_details(){
  cout << "Card Number : " << cardNo << endl;
  cout << "Card Holder Name : " << name << endl;
  cout << "Card Issue Month : " << issueMonth << endl;
  cout << "Card Expiry Month : " << expiryMonth << endl;
  cout << "Card Holder Address : " << addr << endl;
  }

  void set_atm_pin(char *new_pin){
    if((strlen(new_pin) == 4) & (to_string(pin) != new_pin)) pin = stoi(new_pin);
    else{
      cout << "We can not use same pin again or input is not correct." << endl;
      return;
    }
    cout << "ATM pin updted successfully." << endl;
  }

  void update_card_detials(char *im="", char *em="", char *add=""){
    if (im != ""){
      free(issueMonth);
      issueMonth = strdup(im);
      cout << "Issue Month updated successfully.";
    }
    if (em != ""){
      free(expiryMonth);
      expiryMonth = strdup(em);
      cout << "Expiry Month updated successfully.";
    }
    if (add != ""){
      free(addr);
      addr = strdup(add);
      cout << "Address updated successfully.";
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  CreditCard c1(123456789012, "Arun Singh", "Mar", "Dec", "Jamdeeh Pandey Basti", 234);
  cout << "\n:::: Card Details :::: \n";
  c1.get_card_details();
  cout << endl;
  c1.set_atm_pin("2212");
  c1.update_card_detials("", "Jan", "");
  cout << "\n:::: Card Details :::: \n";
  c1.get_card_details();
  cout << endl;
  return 0;
}

/*

:::: Card Details ::::
Card Number : 123456789012
Card Holder Name : Arun Singh
Card Issue Month : Mar
Card Expiry Month : Dec
Card Holder Address : Jamdeeh Pandey Basti

ATM pin updted successfully.
Expiry Month updated successfully.

:::: Card Details ::::
Card Number : 123456789012
Card Holder Name : Arun Singh
Card Issue Month : Mar
Card Expiry Month : Jan
Card Holder Address : Jamdeeh Pandey Basti

*/
