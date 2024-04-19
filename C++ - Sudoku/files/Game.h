#include <vector>

#define _TYPE_ std::vector<std::vector<int>>

class Game
{
  void Sudoku(_TYPE_ &);
  void autoSolve(_TYPE_ &);
  void input(_TYPE_ &);
  void inputRandom(_TYPE_ &);
  bool isValid(_TYPE_ &);
  void printBoard(_TYPE_ &);
  void rowShuffle(_TYPE_ &, const int &);
  void colShuffle(_TYPE_ &, const int &);

public:
  Game();
};