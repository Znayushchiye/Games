#include <Driver.h>

class Player2 : public Driver
{
protected:
  int **board;
  int turns;

public:
  Player2(int **);
  void setBoard(int **);
  int **turn(int **);
  bool hasWon();
};