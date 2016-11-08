#include "Pirate.h"

Pirate::Pirate() {
  this->count = 0;
}

void Pirate::drink_rum() {
  count++;
}

string Pirate::hows_goin_mate() {
  if (count > 4) {
    return "Arrrr!";
  }
  return "Nothin'";
}
