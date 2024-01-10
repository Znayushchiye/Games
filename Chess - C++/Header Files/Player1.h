#include <Driver.h>

class Player1 : public Driver
{
protected:
  int **board;
  int turns;

public:
  Player1(int **);
  void setBoard(int **);
  int **turn(int **);
  bool hasWon();
};