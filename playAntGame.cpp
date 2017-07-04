#include "playAntGame.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


void playAntGame() {
    const int ROWS = 9; // default height
    const int COLS = 9; // default width
    int userRows = 0; // for user to select game height
    int userCols = 0; // for user to select game width

    cout << "Please enter the amount of rows or type '-1' for default values (MAX = 80): ";
    cin >> userRows;
    cout << "Please enter the amount of columns or type '-1' for default values (MAX = 80): ";
    cin >> userCols;

    if (userRows == -1) {
      userRows = ROWS;
    }

    if (userCols == -1) {
      userCols = COLS;
    }

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

  //print board TODO MAKE INTO A FUNCTION
  cout << endl << "Current Game Board:" << endl << endl;
  cout << "  ";
  for (int col = 0; col < userCols; col++) {
    cout << col + 1 << " ";
  }
  cout << endl;

  for (int row = 0; row < userRows; row++) {
    cout << row + 1 << " ";
    for (int col = 0; col < userCols; col++) {
      cout << antBoard[row][col] << " ";
    }
    cout << endl;
  }
//   cout << endl;
// }

     //deallocate memory stored on the heap for the dynamic array
    for (int index = 0; index < userRows; index++) {
      delete[] antBoard[index];
    }
    delete[] antBoard;
}