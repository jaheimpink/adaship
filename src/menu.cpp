#include "../headers/adaship.h"

Menu::Menu()
{
  std::cout << "Welcome to battleship" << std::endl;
  std::cout << "Please pick an option" << std::endl;
  std::cout << "1. Player vs Computer" << std::endl;
  std::cout << "2. Quit              " << std::endl;
  std::cin >> gameChoice;
}

bool Menu::checkGameChoice()
{
  if (gameChoice == 1)
  {
    Gameplay game;
  }
  else if (gameChoice == 2)
  {
    exit(0);
  }
  
  
  do
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter 1 or 2" << std::endl;
    std::cin >> gameChoice;
  } 
  while (std::cin.fail() || (gameChoice != 1 && gameChoice != 2));

  if (gameChoice == 1)
  {
    Gameplay game;
  }
  else if (gameChoice == 2)
  {
    exit(0);
  }
  

}
