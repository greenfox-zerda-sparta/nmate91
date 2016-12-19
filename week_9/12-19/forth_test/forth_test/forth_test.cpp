#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "WordToolbox.h"

#ifndef CATCH_CONFIG_MAIN

int main() {
  WordToolbox w("folate");
  w.setS("folate");
  string alternatives[6] = { "falsetto", "latest", "foetal","aloft","float","flota" };
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getS() << " = " << w.isAnAnagram(alternatives[i]) << endl;
  }
  cout << endl << "New test" << endl;
  w.setS("aloft");
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getS() << " = " << w.isAnAnagram(alternatives[i]) << endl;
  }
  return 0;
}

#endif

#ifdef CATCH_CONFIG_MAIN
#include "Test.h"
#endif

