/****************************************************************
** Author: Daniel Rotenberg
** Date: 7/9/2017
** Description: This program is designed to implement a console
                version of Langston's Ant.
****************************************************************/

// #include "ant.hpp"
#include "menu.hpp"
#include "playAntGame.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
  Menu newMenu;
  cout << endl << "Welcome to Langston's Ant!" << endl;
  newMenu.displayMenu();
  if (newMenu.getInput() == 1) { // option 1 is to play the game
    playAntGame();
  }

  return 0;
}