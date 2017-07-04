#include <iostream>
#include <string>
#include "menu.hpp"
using std::cout;
using std::cin;
using std::string;
using std::endl;

Menu::Menu() {
  return;
}

void Menu::displayMenu() {
    int input;
    cout << endl << "Please choose from the options below, or type '-1' to quit" << endl;
    cout << "Option 1: Play Game" << endl;
    cout << "Option 2: View Board" << endl;
    cout << "Option 3: Replay Game" << endl;
    cout << "To quit, type '-1'" << endl << endl;

    cin >> input;

    if (input == -1) {
      return;
    } else {
      setInput(input);
    }
}

void Menu::setInput(int input) {
  userInput = input;
}

int Menu::getInput(){
  return userInput;
}
