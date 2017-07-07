#include "printBoard.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

void printBoard(char **arr, int boardRows, int boardCols) {
  cout << endl << "Current Game Board:" << endl << endl;
  cout << setw(3) << " ";
  for (int col = 0; col < boardCols; col++) {
    cout << setw(2) << col << " ";
  }
  cout << endl;

  for (int row = 0; row < boardRows; row++) {
    cout << setw(2) << row << " ";
    for (int col = 0; col < boardCols; col++) {
      cout << setw(2) << arr[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl;  
}