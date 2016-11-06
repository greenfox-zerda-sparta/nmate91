#include <iostream>
#include <string>

using namespace std;

int even(int *numbers, int length) {
  int a = 0;
  for (int i = 1; i <= length - 1; i++){
    if (numbers[i] % 2 == 0 && numbers[i-1] % 2 == 0){
      a++;
    }
  }
  return a;
}

int main() {
  int numbers[] = {5, 2, 6, 3, 4, 8, 5, 2, 2, 2};
  int length = sizeof(numbers)/sizeof(*numbers);
  even (numbers, length);
  // Write a function that counts how many times is an even number is folowed by
  // another even number in an array
  cout << even (numbers, length);
  return 0;
}
