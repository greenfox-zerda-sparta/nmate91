#include <iostream>
#include <string>
using namespace std;

void print1(int h) {
  int space = h/2;
  int star = 1;
  for (int i = 0; i < h/2; i++) {
    for(int j = 0; j < space; j++) {
          cout << " ";
        }
    space--;
    for(int j = 0; j < star; j++) {
      cout << "*";
    }
    cout << endl;
    star+=2;
  }
}
void print2 (int h) {
  int star = h-1;
  int space = 1;
  for (int i = h-1; i > 0; i--) {
    for (int j = 0; j < space; j++) {
      cout << " ";
    }
    space++;
    for (int j = 0; j <= star-1; j++){
      cout << "*";
  }
  cout << endl;
  star-=2;
  }
}

void print3 (int h) {
  int star = h-1;
  int space = 1;
  for (int i = h-1; i > 0; i--) {
    for (int j = 0; j < space-1; j++) {
      cout << " ";
    }
    space++;
    for (int j = 0; j <= star; j++){
      cout << "*";
  }
  cout << endl;
  star-=2;
  }
}
int main() {
	int h;
	cout << "Height, please: ";
	cin >> h;
	print1(h);
	if (h % 2 == 0) {
	  print2(h);
	} else {
	  print3(h);
	}
	return 0;
}
