#include <iostream>
#include <string>
// write a function that gets a string as an input
// and appends an 'a' character to its end
using namespace std;
string add(string a, string b) {
    cout << a+b;
    return a+b;
 }

int main() {
  string k = "kuty";
  add(k, "a");
  return 0;
}
