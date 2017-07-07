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

int Ant::getAntCol() {
  return this->antCol;
}

int Ant::getSteps() {
  return this->stepCount;
}

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

  move();
}

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

  move();
}

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


