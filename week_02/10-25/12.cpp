#include <iostream>
#include <string>
// write your own sum function
// it should take an array and it's length
using namespace std;
int sum(int a, int b){
	cout << a+b;
	return a+b;
}
int main() {
  int numbers[] = {4, 5, 6, 7, 8, 9, 10};
  int add=0;
    for (int i=0; i<=4; i++){
  	  add+=numbers[i];
    }
  cout<< "Sum:";
  sum(sizeof(numbers),add);
  cout << endl << sizeof(numbers) << endl << add;
  return 0;
}
