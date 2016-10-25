#include <iostream>
#include <string>
// Tell if g1 is stored in more bytes than g2
using namespace std;

int main() {
  char g1 = 'a';
  double g2 = 12.345;
  if (sizeof(g1) > sizeof(g2)) {
	  cout << "g1 tobb byteban tarolt mint g2" << endl;
  } else {
	  cout << "g1 kisebb" << endl;
  }
  cout << sizeof(g1)<< endl;
  cout << sizeof(g2) << endl;
  return 0;
}
