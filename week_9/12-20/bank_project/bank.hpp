#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Bank {
private:
  double balance;
  string name;
  double bonds;
public:
  Bank(string);
  string get_name();
  double top_up(double);
};


#endif
