#include "bank.hpp"

Bank::Bank(string given_name) {
  this->balance = 0;
  this->name = given_name;
}

double Bank::get_balance() {
  return this->balance;
}

void Bank::decrease_balance(double amount) {
  balance -= amount;
}

string Bank::get_name() {
  return this->name;
}

double Bank::top_up(double amount) {
  balance += amount;
  return balance;
}

Bank Bank::transfer(Bank& other_account, double amount) {
  other_account.top_up(amount);
  decrease_balance(amount);
  return other_account;
}

void Bank::create_a_new_bond(double amount, double interest_rate) {
  decrease_balance(amount);
  Bond bond;
  bonds.push_back(&bond);
  return;
}
 
bool Bank::has_bond_yearly_interest () {
  return bonds[0]->interest_rate;
}
