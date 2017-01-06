#include <iostream>
#include <string>

using namespace std;

int squares(int a[]){
  for (int i = 0; i <= 6; i++){
    a[i] = a[i] * a[i];
    cout << a[i] << " ";
  }
  return *a;
}

int main() {
  // Write a function that takes an array and squares all the elements in the array
  int array [7] = {1, 2, 3, 4, 5, 6, 7};
  squares(array);
  return 0;
}
