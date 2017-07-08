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


void checkEdges(Ant* a, int r, int c) {
  if (a->getAntRow() == r - 1 && a->getDirection() == SOUTH) {
    a->setAntRow(-1);
  }
  if (a->getAntRow() == 0 && a->getDirection() == NORTH) {
    a->setAntRow(r);
  }
  if (a->getAntCol() == c - 1 && a->getDirection() == EAST) {
    a->setAntCol(-1);
  }
  if (a->getAntCol() == 0 && a->getDirection() == WEST) {
    a->setAntCol(c);
  }        
}