#include <ChessPieces.h>
#include <unordered_map>
#define map unordered_map

class Valid : public ChessPieces
{
protected:
  string validPos(string);
  int isValid(string &, int **, int);
  bool isValid(string &, string, int **, int, int);
  bool canMove(string, string, int **, int, int);
  std::map<int, int> countpieces(int **);
};