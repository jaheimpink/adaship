#include "../headers/adaship.h"

Fleet::Fleet() 
{
  Config config;
  boats = config.getBoatConfig(config.configFile);
  boardDimensions = config.getConfig(config.configFile);
}

bool Fleet::validChoice(std::vector<std::vector<std::string>> gameBoard, int xPos, int yPos) 
{
  return gameBoard[xPos][yPos] == " . ";
}

std::vector<std::vector<std::string>> Fleet::updateBoard(std::vector<std::vector<std::string>> gameBoard)
{
  int boatsPlaced = 0;
  int boat = 0;
  char autoDeploy;
  
  while (boatsPlaced < boats.size())
  {
    int row;
    int col;
    char orientation;
    bool shipPlaceSuccess = false;

    while (!shipPlaceSuccess && boatsPlaced < boats.size())
    {
      printBoard(gameBoard);
      shipPlaceSuccess = true;

      while (true)
      {
        std::cout << "Would you like to autoDeploy? Enter 'y' for yes or 'n' for no: ";
        std::cin >> autoDeploy;

        // Check if the input is valid
        if (autoDeploy == 'y' || autoDeploy == 'n' || autoDeploy == 'Y' || autoDeploy == 'N')
        {
          break; // Exit the loop if the input is valid
        }
        else
        {
          std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
          // Clear input buffer to handle invalid input
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
      }

      if (autoDeploy == 'y' || autoDeploy == 'Y')
      {
        row = std::rand() % boardDimensions.first;
        col = std::rand() % boardDimensions.second;
        orientation = (std::rand() % 2 == 0) ? 'v' : 'h';
      }
      else
      {
        std::cout << "Please enter row to place ship " + boats[boat].first + " (e.g 3)" << std::endl;
        std::cin >> row;
        std::cout << "Please enter col to place ship " + boats[boat].first + " (e.g 8)" << std::endl;
        std::cin >> col;
        std::cout << "Please enter the orientation of the ship (v/h)" << std::endl;
        std::cin >> orientation;
      }

      shipPlaceSuccess = tryPlaceShip(gameBoard, boats[boat], row, col, orientation);

      if (!shipPlaceSuccess)
      {
        std::cout << "Invalid placement. Please try again." << std::endl;
      }
    }

    if (shipPlaceSuccess)
    {
      std::cout << "Boat deployed" << std::endl;
      ++boatsPlaced;
      ++boat;
    }

    if (boatsPlaced == boats.size())
    {
      printBoard(gameBoard);
    }
  }

  return gameBoard;
}

std::vector<std::vector<std::string>> Fleet::updateBoardComputer(std::vector<std::vector<std::string>> gameBoard) 
{
  // Seed for random number generation
  std::srand(std::time(0));

  for (const auto &boat : boats)
  {
      bool shipPlaceSuccess = false;

      while (!shipPlaceSuccess)
      {
          char shipSymbol = boat.first[0];

          // Randomly generate starting position
          int row = std::rand() % boardDimensions.first;
          int col = std::rand() % boardDimensions.second;

          // Randomly choose orientation (v/h)
          char orientation = (std::rand() % 2 == 0) ? 'v' : 'h';

          // Attempt to place the ship
          shipPlaceSuccess = tryPlaceShip(gameBoard, boat, row, col, orientation);
      }
  }

  return gameBoard;
}

void Fleet::printBoard(std::vector<std::vector<std::string>> gameBoard) 
{
  int gridCounter = 0;
  std::cout << "  0   1   2   3   4   5   6   7   8   9" << std::endl;

  for (const auto& row : gameBoard) 
  {
    std::cout << gridCounter;
    for (const auto& cell : row) 
    {
      if (cell != " . ")
      {
        std::cout << " " + cell << "  ";
      }
      else
      {
        std::cout << cell << " ";
      }
    }
    std::cout << std::endl;
    ++gridCounter;
  }
}

std::vector<std::vector<std::string>> Fleet::boatRemove(std::vector<std::vector<std::string>> gameBoard, char shipSymbol)
{
  Config cfg;
  std::pair<int, int> dimensions = cfg.getConfig(cfg.configFile);
  
  for (int i = 0; i < dimensions.first; ++i )
  {
    for (int j = 0; j < dimensions.second; ++j) 
    {
      std::cout << gameBoard[i][j] << std::endl;
      if (gameBoard[i][j].find(shipSymbol) != std::string::npos)
      {
        gameBoard[i][j] = " . ";
      }
    }
  }

  return gameBoard;
}

bool Fleet::tryPlaceShip(std::vector<std::vector<std::string>> &gameBoard, const std::pair<std::string, int> &boat, int startRow, int startCol, char orientation)
{
  int row = startRow;
  int col = startCol;

  if (orientation == 'v')
  {
    // Check if there is enough space vertically
    if (row + boat.second > boardDimensions.first)
    {
      return false;
    }

    // Check if the positions are empty
    for (int i = row; i < (boat.second + row); ++i)
    {
      if (!validChoice(gameBoard, i, col))
      {
        return false;
      }
    }

    // Place the ship
    for (int i = row; i < (boat.second + row); ++i)
    {
      gameBoard[i][col] = boat.first[0];
    }
  }
  else if (orientation == 'h')
  {
    // Check if there is enough space horizontally
    if (col + boat.second > boardDimensions.second)
    {
      return false;
    }

    // Check if the positions are empty
    for (int i = col; i < (boat.second + col); ++i)
    {
      if (!validChoice(gameBoard, row, i))
      {
        return false;
      }
    }

    // Place the ship
    for (int i = col; i < (boat.second + col); ++i)
    {
      gameBoard[row][i] = boat.first[0];
    }
  }

  return true;
}

bool Fleet::allShipsDestroyed(std::vector<std::vector<std::string>> gameBoard) 
{
  Config cfg;
  std::pair<int, int> dimensions = cfg.getConfig(cfg.configFile);
  
  for (int i = 0; i < dimensions.first; ++i )
  {
    for (int j = 0; j < dimensions.second; ++j) 
    {
      if (gameBoard[i][j] != " . " && gameBoard[i][j] != "X" && gameBoard[i][j] != "O")
      {
        return false;
      }
    }
  }

  return true;
}
