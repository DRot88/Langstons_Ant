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
    cout << endl << "Please choose from the options below." << endl;
    cout << "Option 1: Play Game" << endl;
    cout << "Option 2: Quit" << endl << endl;

    cin >> input;

    if (input == 2) {
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
