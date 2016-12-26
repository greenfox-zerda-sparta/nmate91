#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Bond {
  double amount;
  double interest_rate;
};

class Bank {
private:
  double balance;
  string name;
  vector<Bond*> bonds;
  void decrease_balance(double);
public:
  Bank(string);
  string get_name();
  double get_balance();
  double top_up(double);
  Bank transfer(Bank&, double);
  void create_a_new_bond(double, double);
  bool has_bond_yearly_interest();
};


#endif
