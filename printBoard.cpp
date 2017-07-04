#include "printBoard.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void printBoard(char **arr, int boardRows, int boardCols) {
  cout << endl << "Current Game Board:" << endl << endl;
  cout << "  ";
  for (int col = 0; col < boardCols; col++) {
    cout << col << " ";
  }
  cout << endl;

  for (int row = 0; row < boardRows; row++) {
    cout << row << " ";
    for (int col = 0; col < boardCols; col++) {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl;  
}