#include <iostream>
using namespace std;

void safeUnion(int *a, int l_a, int *b, int l_b, int *result, int l_res) {
  // Implement this function to create the union of a and b into the array result!
  for (int i = 0; i < l_res; i++) { //0-tol szamolva a_l hosszig
      if (i < l_a) {
        result[i] = a[i]; //a result arraybe i. helyre beleirja a array i. elemet
      }
      else { // ha leporgott a_l-ig, menjen tovabb ily modon, es irja bele a result array (i-b_l). helyere
        result[i] = b[i-l_b];
      }
    }
  }

int main(int argc, char** argv) {
  int a[3] = {1,2,3};
  int b[3] = {4,5,6};
  int c[6];
  safeUnion(a,3,b,3,c,6);
  for (int i = 0; i<6; i++) cout << c[i] << endl;
return 0;
}
