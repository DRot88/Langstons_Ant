#include "ant.hpp"
#include <iostream>
using std::cout;
using std::endl;


Ant::Ant() {
  stepCount = 0;
  antRow = 2;
  antCol = 2;
  currentDir = WEST;
}

void Ant::increaseSteps() {
  stepCount += 1;
}

int Ant::getAntRow() {
  return this->antRow;
}

int Ant::getAntCol() {
  return this->antCol;
}

