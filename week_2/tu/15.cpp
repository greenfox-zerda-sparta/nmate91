#include <iostream>
#include <string>
// Write a function that takes ana array, its length and a number
// and it returns the index of the given number in the array.
// It should return -1 if did not find it. (linear search)
using namespace std;

int index(int numbers[], int length, int num){
	for(int i = 0; i < length; i++){
	  if (num == numbers[i]){
		  return i;
		}
	}
	return -1;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  int num, length = sizeof(numbers)/sizeof(int);
  cout << "gimme a num: ";
  cin >> num;
  cout << index(numbers, length, num);

  return 0;
}
