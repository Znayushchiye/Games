#include <iostream>

class game
{
private:
  char board[3][3];
  char player;

  void setBoard();
  void printBoard();
  inline void setPlayer(char);
  inline char getPlayer();
  void play();
  bool gameOver();
  void togglePlayer();
  char checkWin();

public:
  game();
};

// Works
game::game()
{
  setBoard();
  setPlayer('X');
  play();
}

// Works
void game::setBoard()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = '-';
    }
  }
}

// Works
void game::printBoard()
{
  std::cout << "-------------\n";
  for (int i = 0; i < 3; i++)
  {
    std::cout << "| ";
    for (int j = 0; j < 3; j++)
    {
      std::cout << board[i][j] << " | ";
    }
    std::cout << "\n-------------\n";
  }
}

// Works
inline void game::setPlayer(char letter)
{
  player = letter;
}

// Works
inline char game::getPlayer()
{
  return player;
}

// Works
void game::play()
{
  printBoard();
  int minReqMoves = 5;
  while ((minReqMoves-- > 0) || !gameOver())
  {
    int row, column;
    std::cout << "Player " << ((player == 'X') ? "1" : "2") << std::endl;
    std::cout << "Enter row and column: ";
    std::cin >> row >> column;
    row--;
    column--;
    if (board[row][column] != '-')
    {
      std::cout << "Invalid move, try again.\n";
      continue;
    }
    board[row][column] = player;
    togglePlayer();
    printBoard();
    std::cout << std::endl;
  }

  char winningPlayer = checkWin();
  if (winningPlayer == 'X')
  {
    std::cout << "Player 1 wins!\n";
  }
  else if (winningPlayer == 'O')
  {
    std::cout << "Player 2 wins!\n";
  }
  else
  {
    std::cout << "Draw!\n";
  }
}

// Works
void game::togglePlayer()
{
  if (getPlayer() == 'X')
  {
    setPlayer('O');
  }
  else
  {
    setPlayer('X');
  }
}

// Works
bool game::gameOver()
{
  char player = checkWin();
  if (player != '-')
  {
    return true;
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == '-')
      {
        return false;
      }
    }
  }
  return true;
}

// Works
char game::checkWin()
{
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
    {
      return board[i][0];
    }
  }
  for (int i = 0; i < 3; i++)
  {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
    {
      return board[0][i];
    }
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
  {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
  {
    return board[2][0];
  }
  return '-';
}

// Works
int main()
{
  std::cout << "------------------------------------------------------------\n";
  std::cout << "Welcome to Tic Tac Toe!\n";
  game Game;
  std::cout << "\n------------------------------------------------------------";
  return 0;
}