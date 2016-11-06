#include <iostream>
#include <string>

// Create a game that figures a number that the user picked between 0 and 10
// It should ask questions like:
//  - Is the number greater than 5? [y/n]
//  - Is the number smaller than 4? [y/n]
// (don't have to ask both kind)
//
// It should wait for input after the question
//
// If the answer is not "y" or "n" it should re-ask the question;
//
// If the program knows enough it should tell the picked number like:
// Your number is: 8

using namespace std;

int guess(){
  bool input;
  cout << "- Is the number greater than 5? [y=1/n=0] ";
  cin >> input;
  if (input == 1) {
    cout << "- Is the number greater than 7? [y=1/n=0] ";
    cin >> input;
    if (input == 1) {
      cout << "- Is the number greater than 9? [y=1/n=0] ";
      cin >> input;
      if (input == 1) {
        cout << "Your number is 10.";
      } else {
        cout << "- Is the number less than 9? [y=1/n=0] ";
        cin >> input;
        if (input == 1) {
          cout << "Your number is 8.";
        } else {
          cout << "Your number is 9.";
        }
      }
    } else {
      cout << "Your number is 6.";
    }
  } else {
    cout << "- Is the number less than 3? [y=1/n=0] ";
    cin >> input;
    if (input == 1) {
      cout << "- Is the number less than 1? [y=1/n=0] ";
      cin >> input;
      if (input == 1) {
        cout << "Your number is 0.";
      } else {
        cout << "- Is the number greater than 1? [y=1/n=0] ";
        cin >> input;
        if (input == 1) {
          cout << "Your number is 2.";
        } else {
          cout << "Your number is 1.";
        }
      }
    } else {
      cout << "- Is the number greater than 4? [y=1/n=0] ";
      cin >> input;
      if (input == 1) {
        cout << "Your number is 5.";
      } else {
        cout << "- Is the number greater than 3? [y=1/n=0] ";
        cin >> input;
        if (input == 1) {
          cout << "Your number is 4.";
        } else {
          cout << "Your number is 3.";
        }
      }
    }
  }
  return 0;
}

int main() {
  guess();
  return 0;
}
