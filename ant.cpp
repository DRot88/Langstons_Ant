#include "ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

//default constructor
Ant::Ant() {
  stepCount = 0;
  antRow = 2;
  antCol = 2;
  currentDir = WEST;
}

void Ant::increaseSteps() {
  this->stepCount += 1;
}

int Ant::getAntRow() {
  return this->antRow;
}

void Ant::setAntRow(int r) {
  this->antRow = r;
}

void Ant::setAntCol(int c) {
  this->antCol = c;
}

int Ant::getAntCol() {
  return this->antCol;
}

int Ant::getSteps() {
  return this->stepCount;
}

/*********************************************************************
** Function: turnRight
** Description: This function turns the ant right, based on the
                current direction it is facing.
**********************************************************************/

void Ant::turnRight() {
  if (currentDir == WEST) {
    currentDir = NORTH;
  } else if (currentDir == EAST) {
    currentDir = SOUTH;
  } else if (currentDir == NORTH) {
    currentDir = EAST;
  } else {
    currentDir = WEST;
  }
}

/*********************************************************************
** Function: turnRight
** Description: This function turns the ant left, based on the
                current direction it is facing.
**********************************************************************/

void Ant::turnLeft() {
  if (currentDir == WEST) {
    currentDir = SOUTH;
  } else if (currentDir == EAST) {
    currentDir = NORTH;
  } else if (currentDir == NORTH) {
    currentDir = WEST;
  } else {
    currentDir = EAST;
  }
}

/*********************************************************************
** Function: turnRight
** Description: This function moves the ant forward one unit, based on
                the current direction it is facing. After moving forward,
                it calls the increaseSteps function to keep track of
                the amount of times it has moved.
**********************************************************************/
void Ant::move() {
  if (currentDir == WEST) {
    antCol -= 1;
  } else if (currentDir == EAST) {
    antCol += 1;
  } else if (currentDir == NORTH) {
    antRow -= 1;
  } else {
    antRow += 1;
  }
  increaseSteps();
}

Direction Ant::getDirection() {
  return this-> currentDir;
}

