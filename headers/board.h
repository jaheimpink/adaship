
#include <utility>
#include <vector>

class Board {
	private:
	  

	public:
	  std::pair <int,int> boardConfig;
	  std::pair <int,int> attackCoords;
	  std::vector <std::vector<std::string> > gameBoard;
	  
	  
	  void printBoard();
	  void boatRemove(std::vector <std::vector<std::string> > gameBoard, std::string shipSymbol);
	  std::vector <std::vector<std::string> > shoot(std::pair <int,int> attackCoords);
	  std::pair <std::vector <std::vector<std::string> >,std::vector <std::vector<std::string> > > wasHit(std::pair <int,int> attackCoords, std::vector <std::vector<std::string> > gameBoardAttack, std::vector <std::vector<std::string> > gameBoard);
	  std::pair <int,int> inputCoords();

	  void setAttackCoords(std::pair<int, int> coords) {
        attackCoords = coords;
      }

	  friend class Fleet;
	  
	  Board();

};
