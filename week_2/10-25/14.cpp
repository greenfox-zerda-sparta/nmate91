#include <iostream>
#include <string>
  // Write a function that takes an array and its length, returns the minimal element
  // in the array (your own min function)
using namespace std;

int minimum(int array[], int length){
	int minelement = array[0];
	for(int i = 0; i < length; i++){
		if (minelement > array[i]){
			minelement = array[i];
		}
	}
	return minelement;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  int length = sizeof(numbers)/sizeof(int);
  cout << minimum(numbers, length);

  return 0;
}
