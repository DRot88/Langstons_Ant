/****************************************************************
** Author: Daniel Rotenberg
** Date: 7/9/2017
** Description: This program is designed to implement a console
                version of Langston's Ant.
****************************************************************/

#include "playAntGame.hpp"
#include "printBoard.hpp"
#include "ant.hpp"
#include "validation.hpp"
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Function: playAntGame
** Description: This function is designed to implement Langston's
                Ant in the console. It asks the users for inputs to
                create the board size, location of ant, and how many
                steps the ant will make before stopping.
**********************************************************************/

void playAntGame() {
    const int ROWS = 9; // default height
    const int COLS = 9; // default width
    const int STEPS = 9; // default steps
    const char WHITE = ' '; // white space
    const char BLACK = '#'; // black space
    int userRows = 0; // for user to select game height
    int userCols = 0; // for user to select game width
    int totalSteps = 0; // for user to select total moves of the ant
    int startRow = 0; // for user to select starting row
    int startCol = 0; // for user to select starting col
    char lastPosition;
    Ant langAnt;

    // ask user for rows on the board
    cout << "Please enter the amount of rows or type '-1' for default values (MIN = 5, MAX = 50): ";
    do {
      cin >> userRows;
    } while (!isValidInt(userRows));

    // if '-1', use default values
    if (userRows == -1) {
      userRows = ROWS;
    }

    // ask user for columns on the board
    cout << "Please enter the amount of columns or type '-1' for default values (MIN = 5, MAX = 50): ";
    do {
      cin >> userCols;
    } while (!isValidInt(userCols));

    // if '-1', use default values
    if (userCols == -1) {
      userCols = COLS;
    }

    // ask user for amount of steps to be made by the ant
    cout << "Please enter the amount of steps you would like the Ant to make (MIN = 5, MAX = 50, DEFAULT = -1): ";
    do {
      cin >> totalSteps;
    } while (!isValidInt(totalSteps));

    // if '-1', use default values
    if (totalSteps == -1) {
      totalSteps = STEPS;
    }

    // select starting location (row) or randomize
    cout << "What row would you like the ant to start in? (0 - " << userRows - 1 
         << " [or type -1 for a random row]): ";
    do {
      if (startRow < -1 || startRow > userRows - 1) {
        cout << "That is an invalid option, please try again: ";
      }
      cin >> startRow;
    } while (startRow < -1 || startRow > userRows - 1);

    // if user selects random, set starting row randomly using time and modulo
    if (startRow == -1) {
      startRow = time(0) % userRows;
      cout << "Random Row: " << startRow << endl;
    }

    // select starting location (column) or randomize
    cout << "What column would you like the ant to start in? (0 - " << userCols - 1 
         << " [or type -1 for a random column]): ";
    do {
      if (startCol < -1 || startCol > userCols - 1) {
        cout << "That is an invalid option, please try again: ";
      }      
      cin >> startCol;
    } while (startCol < -1 || startCol > userCols - 1);

    // if user selects random, set starting column randomly using time and modulo
    if (startCol == -1) {
      startCol = time(0) % userCols;
      cout << "Random Column: " << startCol << endl;
    }

    langAnt.setAntRow(startRow);
    langAnt.setAntCol(startCol);
    
    // dynamically allocate array for ant board
    char **antBoard = new char*[userRows];
    for (int i = 0; i < userRows; i++) {
      antBoard[i] = new char[userCols];
    }

    // set board to be WHITE values
    for (int r = 0; r < userRows; r += 1) {
      for (int c = 0; c < userCols; c += 1) {
        antBoard[r][c] = WHITE;
      }
    } 

   
    cout << endl << "The ant will start at row: " << langAnt.getAntRow() << ", column: " << langAnt.getAntCol();
    cout << endl << "Total Steps Taken: " << langAnt.getSteps() << endl;

    lastPosition = antBoard[langAnt.getAntRow()][langAnt.getAntCol()];
    antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = ANT;
    printBoard(antBoard, userRows, userCols);

    // loops until ant has reached the total # of steps allocated by user
    // changes cell colors, controls ant position and turning
    while (langAnt.getSteps() < totalSteps) {
      if (lastPosition == WHITE) { 
        antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = BLACK;
        langAnt.turnRight();
        checkEdges(&langAnt, userRows, userCols);    
        langAnt.move();
        lastPosition = antBoard[langAnt.getAntRow()][langAnt.getAntCol()];
        antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = ANT;
      } else if (lastPosition == BLACK) {
        antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = WHITE;
        langAnt.turnLeft();
        checkEdges(&langAnt, userRows, userCols);     
        langAnt.move();
        lastPosition = antBoard[langAnt.getAntRow()][langAnt.getAntCol()];
        antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = ANT;
    }

    // prints steps taken and the current board
    cout << endl << "Total Steps Taken: " << langAnt.getSteps() << endl;
    printBoard(antBoard, userRows, userCols);    
  }
 
     //deallocate memory stored on the heap for the dynamic array
    for (int index = 0; index < userRows; index++) {
      delete[] antBoard[index];
    }
    delete[] antBoard;
}