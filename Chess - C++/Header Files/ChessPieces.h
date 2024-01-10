#include <iostream>
#define string std::string

class ChessPieces
{
protected:
  bool pawn(string, string, int **, int);
  bool pawn(string, string, int, int **);
  bool rook(string, string, int **, int);
  bool bishop(string, string, int **, int);
  bool knight(string, string, int **, int);
  bool king(string, string, int **, int);
  bool queen(string, string, int **, int);
};