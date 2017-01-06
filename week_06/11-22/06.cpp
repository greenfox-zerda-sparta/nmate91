#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
  srand(time(NULL)); // This initializes the random generator
  int rnd = 0;
  for (int i=0; i<20; i++) {
    rnd = rand() % 5; // generate a random number in the range [0, 4]
    try {
      switch (rnd) {
        case 0:
	  throw 3.2f;
	  break;
	case 1:
	  throw double(43.56);
	  break;
	case 2:
	  throw "Abrakadabra";
	  break;
	case 3:
          throw false;
	  break;
	case 4:
	  throw 12;
	  break;
	}
      }
      catch(float a) {
        cout << "float and " << a << endl;
      }
      catch(double b) {
        cout << "double and " << b << endl;
      }
      catch(const char* c) {
        cout << "string and " << c << endl;
      }
      catch(bool d) {
        cout << "bool and " << d << endl;
      }
      catch(int e) {
        cout << "int and " << e << endl;
      }
    }
  return 0;
}
