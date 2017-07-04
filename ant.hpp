#ifndef ANT_HPP
#define ANT_HPP

enum Direction {WEST, NORTH, EAST, SOUTH};

class Ant {
private:
  char* currentCell; // to hold the location of the ant
  char* lastCell; //previous cell to adjust color;
  Direction currentDir;
  int stepCount; // track how far the ant has moved
  int antRow;
  int antCol;

public:
  Ant(); //default constructor
  Ant(int startRow, int startCol, Direction); //constructor
  void move();
  void increaseSteps();
  int getAntRow();
  int getAntCol();
};

#endif