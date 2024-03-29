#ifndef ANT_HPP
#define ANT_HPP

enum Direction {WEST, NORTH, EAST, SOUTH};
const char ANT = '@'; // ant on board

class Ant {
private:
  Direction currentDir;
  int stepCount; // track how far the ant has moved
  int antRow;
  int antCol;

public:
  Ant(); //default constructor
  void move();
  void turnRight();
  void turnLeft();
  void increaseSteps();
  void setAntRow(int r);
  void setAntCol(int c);
  int getSteps();
  int getAntRow();
  int getAntCol();
  Direction getDirection();
};

#endif