#ifndef ANT_HPP
#define ANT_HPP

enum Direction {WEST, NORTH, EAST, SOUTH};

class Ant {
private:
  Direction currentDir;
  int stepCount; // track how far the ant has moved
  int antRow;
  int antCol;

public:
  Ant(); //default constructor
  Ant(int startRow, int startCol, Direction); //constructor
  void move();
  void turnRight();
  void turnLeft();
  void increaseSteps();
  int getSteps();
  int getAntRow();
  int getAntCol();
};

#endif