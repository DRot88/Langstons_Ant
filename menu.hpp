#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Menu {
private:
  int userInput;
public:
  Menu();
  void displayMenu();
  void setInput(int); 
  int getInput();
};