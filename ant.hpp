#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
  int *currentCell; // to hold the location of the ant
  void direction;
  int stepCount = 0;

public:
  Ant(); //default constructor
  Ant(int* startingCell, void direction); //constructor
  void move();
};

#endif