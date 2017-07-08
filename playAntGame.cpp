#include "playAntGame.hpp"
#include "printBoard.hpp"
#include "ant.hpp"
#include "validation.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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

    cout << "Please enter the amount of rows or type '-1' for default values (MIN = 5, MAX = 50): ";
    do {
      cin >> userRows;
    } while (!isValidInt(userRows));

    if (userRows == -1) {
      userRows = ROWS;
    }

    cout << "Please enter the amount of columns or type '-1' for default values (MIN = 5, MAX = 50): ";
    do {
      cin >> userCols;
    } while (!isValidInt(userCols));

    if (userCols == -1) {
      userCols = COLS;
    }

    cout << "Please enter the amount of steps you would like the Ant to make (MIN = 5, MAX = 50): ";
    do {
      cin >> totalSteps;
    } while (!isValidInt(totalSteps));

    if (totalSteps == -1) {
      totalSteps = STEPS;
    }

    cout << "What row would you like the ant to start in? (0 - " << userRows - 1 << "): ";
    do {
      if (startRow < 0 || startRow > userRows - 1) {
        cout << "That is an invalid option, please try again: ";
      }
      cin >> startRow;
    } while (startRow < 0 || startRow > userRows - 1);

    cout << "What column would you like the ant to start in? (0 - " << userCols - 1 << "): ";
    do {
      if (startCol < 0 || startCol > userCols - 1) {
        cout << "That is an invalid option, please try again: ";
      }      
      cin >> startCol;
    } while (startCol < 0 || startCol > userCols - 1);

    langAnt.setAntRow(startRow);
    langAnt.setAntCol(startCol);
    
    //dynamically allocate array for ant board
    char **antBoard = new char*[userRows];
    for (int i = 0; i < userRows; i++) {
      antBoard[i] = new char[userCols];
    }

    for (int r = 0; r < userRows; r += 1) {
      for (int c = 0; c < userCols; c += 1) {
        antBoard[r][c] = WHITE;
      }
    } 

    cout << endl << "Total Steps Taken: " << langAnt.getSteps() << endl;
    cout << "The ant will start at row: " << langAnt.getAntRow() << ", column: " << langAnt.getAntCol();
    cout << endl << endl;

    lastPosition = antBoard[langAnt.getAntRow()][langAnt.getAntCol()];
    antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = ANT;
    printBoard(antBoard, userRows, userCols);

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

    cout << endl << "Total Steps Taken: " << langAnt.getSteps() << endl;
    printBoard(antBoard, userRows, userCols);    
  }
 
     //deallocate memory stored on the heap for the dynamic array
    for (int index = 0; index < userRows; index++) {
      delete[] antBoard[index];
    }
    delete[] antBoard;
}