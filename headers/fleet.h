#include <vector>
#include <utility>

class Fleet 
{
    public:
     std::vector <std::pair <std::string,int> > boats;
     std::pair <int,int> boardDimensions;

     


     Fleet();
     bool validChoice(std::vector <std::vector<std::string> > gameBoard, int xPos, int yPos);
     std::vector <std::vector<std::string> > boatRemove(std::vector <std::vector<std::string> > gameBoard, char shipSymbol);
     std::vector <std::vector<std::string> > updateBoard(std::vector <std::vector<std::string> > gameBoard);
     std::vector <std::vector<std::string> > updateBoardComputer(std::vector <std::vector<std::string> > gameBoard);
     void printBoard(std::vector <std::vector<std::string> > gameBoard);
     bool tryPlaceShip(std::vector<std::vector<std::string> > &gameBoard, const std::pair<std::string, int> &boat, int startRow, int startCol, char orientation);
     bool allShipsDestroyed(std::vector <std::vector<std::string> > gameBoard);




};