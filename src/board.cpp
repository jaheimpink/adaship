#include "../headers/adaship.h"

Board::Board() : boardConfig(Config().getConfig("config.ini"))
{
  Config gameconfig;
  boardConfig = gameconfig.getConfig(gameconfig.configFile);
  gameBoard = std::vector<std::vector<std::string> >(boardConfig.first, std::vector<std::string>(boardConfig.second, " . "));
}

void Board::printBoard() {
  int gridCounter = 0;
  std::cout << " 0   1   2   3   4   5   6   7   8   9" << std::endl;

  for (const auto& row : gameBoard) {
    std::cout << gridCounter;
    for (const auto& cell : row) {
      if (cell != " . ") {
        std::cout << " " + cell + "  ";
      } else {
        std::cout << cell << " ";
      }
    }
    std::cout << std::endl;
    ++gridCounter;
  }
}

void Board::boatRemove(std::vector<std::vector<std::string> > gameBoard, std::string shipSymbol) {
  int counter = 0;
  int counter2 = 0;
  for (const auto& row : gameBoard) {
    counter++;
    for (const auto& cell : row) {
      counter2++;
      if (cell.find(shipSymbol) != std::string::npos) {
        gameBoard[counter][counter2] = " . ";
      }
    }
  }
}

std::vector<std::vector<std::string> > Board::shoot(std::pair<int, int> attackCoords) {
  gameBoard[attackCoords.first][attackCoords.second] = "X";
  return gameBoard;
}

std::pair<int, int> Board::inputCoords() {
  int x;
  int y;
  std::pair<int, int> attackCoords;

  while (true) {
    std::cout << "Enter x: " << std::endl;
    std::cin >> x;

    // Check if the input is a valid integer
    if (std::cin.fail()) {
      std::cout << "Invalid input. Please enter a valid integer." << std::endl;
      // Clear input buffer and ignore invalid input
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      break; // Exit the loop if the input is valid
    }
  }

  while (true) {
    std::cout << "Enter y: " << std::endl;
    std::cin >> y;

    // Check if the input is a valid integer
    if (std::cin.fail()) {
      std::cout << "Invalid input. Please enter a valid integer." << std::endl;
      // Clear input buffer and ignore invalid input
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      break; // Exit the loop if the input is valid
    }
  }

  attackCoords = std::make_pair(x, y);
  return attackCoords;
}

std::pair<std::vector<std::vector<std::string> >, std::vector<std::vector<std::string> > > Board::wasHit(
    std::pair<int, int> attackCoords, std::vector<std::vector<std::string> > gameBoardAttack,
    std::vector<std::vector<std::string> > gameBoard) {
  Config cfg;
  std::pair<int, int> dimensions = cfg.getConfig(cfg.configFile);

  if (gameBoard[attackCoords.first][attackCoords.second] != "X" &&
      gameBoard[attackCoords.first][attackCoords.second] != " . ") {
    std::cout << "Hit" << std::endl;
    gameBoard[attackCoords.first][attackCoords.second] = "X";
    gameBoardAttack[attackCoords.first][attackCoords.second] = "X";
  } else {
    std::cout << "Miss" << std::endl;
    gameBoard[attackCoords.first][attackCoords.second] = "O";
    gameBoardAttack[attackCoords.first][attackCoords.second] = "O";
  }
  std::pair<std::vector<std::vector<std::string> >, std::vector<std::vector<std::string> > > gameBoards =
      std::make_pair(gameBoard, gameBoardAttack);
  return gameBoards;
}

std::pair<int, int> randomCoords(std::pair<int, int> boardDimensions) {
  int row = std::rand() % boardDimensions.first;
  int col = std::rand() % boardDimensions.second;
  return std::make_pair(row, col);
}
