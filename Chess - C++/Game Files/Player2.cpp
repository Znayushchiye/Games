#include "../Header Files/Player2.h"

Player2::Player2(int **board)
{
   turns = 0;
   setBoard(board);
}
void Player2::setBoard(int **board)
{
   this->board = board;
}
bool Player2::hasWon()
{
   std::map<int, int> pieces = countpieces(board);
   if (pieces[6] == 0)
      return true;
   return false;
}
int **Player2::turn(int **currentBoard)
{
   turns++;
   setBoard(currentBoard);
   return driver(2, currentBoard, turns);
}