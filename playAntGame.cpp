#include "playAntGame.hpp"
#include "printBoard.hpp"
#include "ant.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void playAntGame() {
    const int ROWS = 9; // default height
    const int COLS = 9; // default width
    int userRows = 0; // for user to select game height
    int userCols = 0; // for user to select game width
    int steps = 0; // for user to select total moves of the ant
    int totalSteps = 0;

    cout << "Please enter the amount of rows or type '-1' for default values (MIN = 5, MAX = 80): ";
    cin >> userRows;
    if (userRows == -1) {
      userRows = ROWS;
    }

    cout << "Please enter the amount of columns or type '-1' for default values (MIN = 5, MAX = 80): ";
    cin >> userCols;
    if (userCols == -1) {
      userCols = COLS;
    }

    cout << "Please enter the amount of steps you would like the Ant to make: ";
    cin >> steps;

    //dynamically allocate array for ant board
    char **antBoard = new char*[userRows];
    for (int i = 0; i < userRows; i++) {
      antBoard[i] = new char[userCols];
    }

    for (int r = 0; r < userRows; r += 1) {
      for (int c = 0; c < userCols; c += 1) {
        antBoard[r][c] = '-';
      }
    } 

    Ant langAnt;
    antBoard[langAnt.getAntRow()][langAnt.getAntCol()] = '@';

    cout << endl << "Total Steps: " << totalSteps << endl;
    printBoard(antBoard, userRows, userCols);

     //deallocate memory stored on the heap for the dynamic array
    for (int index = 0; index < userRows; index++) {
      delete[] antBoard[index];
    }
    delete[] antBoard;
}