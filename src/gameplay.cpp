#include "../headers/adaship.h"

Gameplay::Gameplay()
{
  Fleet Player1;
  Board Player1Placement;
  Fleet Computer;
  Board ComputerPlacement;
  Board Player1Attack;
  Board ComputerAttack;
  Player humanPlayer;
  Player computer;
  Config gameplaycfg;
  bool setupComplete = false; 
  bool win = false;
  computer.isTurn = false;

  std::cout << "Beginning Fleet Deployment" << std::endl << std::endl;
  Player1Placement.gameBoard = Player1.updateBoard(Player1Placement.gameBoard);
  setupComplete = true;
  
  if (setupComplete) {
    ComputerPlacement.gameBoard = Computer.updateBoardComputer(ComputerPlacement.gameBoard);
    ComputerPlacement.printBoard();
  }

  while (!win) 
  {
    if (humanPlayer.isTurn) 
    {
      std::cout << "Your Turn" << std::endl;
      Player1Attack.setAttackCoords(Player1Attack.inputCoords());
      Player1Attack.gameBoard = Player1Attack.wasHit(Player1Attack.attackCoords, Player1Attack.gameBoard, ComputerPlacement.gameBoard).second;
      ComputerPlacement.gameBoard = Player1Placement.wasHit(Player1Attack.attackCoords, Player1Attack.gameBoard, ComputerPlacement.gameBoard).first;

      std::cout << "Your Board" << std::endl;
      Player1Placement.printBoard();
      std::cout << std::endl;
      std::cout << "Attack Board" << std::endl;
      Player1Attack.printBoard();

      if (Computer.allShipsDestroyed(ComputerPlacement.gameBoard))
      {
        std::cout << "You win" << std::endl;
        win = true;
      }

      humanPlayer.isTurn = false;
      computer.isTurn = true;
    }
    else if (computer.isTurn) 
    {
      std::cout << "Computer's turn" << std::endl;
      
      int x = std::rand() % Computer.boardDimensions.first;
      int y = std::rand() % Computer.boardDimensions.second;

      ComputerAttack.attackCoords = std::make_pair(x, y);

      Player1Placement.gameBoard = ComputerPlacement.wasHit(ComputerAttack.attackCoords, ComputerAttack.gameBoard, Player1Placement.gameBoard).first;

      if (Player1.allShipsDestroyed(Player1Placement.gameBoard))
      {
        std::cout << "You win" << std::endl;
        win = true;
      }

      humanPlayer.isTurn = true;
      computer.isTurn = false;
    }
    else if (Player1.allShipsDestroyed(Player1Placement.gameBoard)) 
    {
      std::cout << "You win" << std::endl;
      win = true;
    }
    else if (Computer.allShipsDestroyed(ComputerPlacement.gameBoard))
    {
      std::cout << "Computer wins" << std::endl;
      win = true;
    }
  }
}
