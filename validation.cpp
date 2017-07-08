#include "validation.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int MIN = 5;
const int MAX = 50;
const int DEFAULT = -1;

bool isValidInt(int x) {
  if ( ((x >= MIN) && (x <= MAX)) || x == DEFAULT ) {
    return true;
  } else {
    cout << "The integer entered is invalid, please enter a value between " << MIN << " and " << MAX << endl;
    return false;
  }
}