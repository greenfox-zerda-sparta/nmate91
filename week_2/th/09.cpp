#include <iostream>
#include <string>
using namespace std;

int print1(int h) {
  int space = h/2, star = 1;
    for (int i = 0; i < h/2; i++) {
      for(int j = 0; j < space; j++) {
            cout << " ";
          }
      for(int j = 0; j < star; j++) {
        cout << "*";
      }
      cout << endl;
      star+=2;
      space--;
    }
    return 0;
  }

int print2 (int h) {
  int star = h;
  int space = 0;
  for (int i = h/2; i >= 0; i--) {
    for (int j = 0; j < space; j++) {
      cout << " ";
    }
    for (int j = 0; j <= star; j++){
      cout << "*";
  }
  cout << endl;
	star-=2;
  space++;
 }
return 0;
}

int main() {
	int h;
	cout << "Height, please: ";
	cin >> h;
	print1(h);
	print2(h);
	return 0;
}
