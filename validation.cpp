#include "validation.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int MIN = 5;
const int MAX = 50;
const int DEFAULT = -1;

/*********************************************************************
** Function: isValidInt
** Description: This function takes an int as an argument and checks 
                to see if it either falls within the min/max values
                allowed, or if it is equal to the default value.
**********************************************************************/

bool isValidInt(int x) {
  if ( ((x >= MIN) && (x <= MAX)) || x == DEFAULT ) {
    return true;
  } else {
    cout << "The integer entered is invalid, please enter a value between " << MIN << " and " << MAX << endl;
    return false;
  }
}

/*********************************************************************
** Function: checkEdges
** Description: This function takes an Ant, and the row and columns as
                arguments. If the ant is at an "edge" of the array,
                it repositions the ant to be on the opposite side of the 
                array before it is moved foward.
**********************************************************************/

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