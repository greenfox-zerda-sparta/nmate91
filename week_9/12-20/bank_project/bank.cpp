#include "bank.hpp"

Bank::Bank(string given_name) {
  this->balance = 0;
  this->bonds = 0;
  this->name = given_name;
}

string Bank::get_name() {
  return this->name;
}

double Bank::top_up(double amount) {
  balance += amount;
  return balance;
}
