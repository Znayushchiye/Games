#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <set>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

class Solution
{
private:
  std::set<vvi> states;
  int neighbours(vvi &, int, int);
  void printBoard(const vvi &);
  vvi input();

public:
  void gameOfLife();
};

int Solution::neighbours(vvi &board, int r, int c)
{
  int rows = board.size();
  int cols = board[0].size();
  int count = 0;

  int directions[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i)
  {
    int nr = r + directions[i][0];
    int nc = c + directions[i][1];
    if (0 <= nr && nr < rows && 0 <= nc && nc < cols)
    {
      count += board[nr][nc];
    }
  }
  return count;
}
void Solution::printBoard(const vvi &board)
{
  int rows = board.size();
  int cols = board[0].size();

  // for (int i = 0; i < cols; i++)
  //   std::cout << "---";
  std::cout << std::endl;
  for (int i = 0; i < rows; i++)
  {
    std::cout << "| ";
    for (int j = 0; j < cols; j++)
    {
      if (board[i][j])
        std::cout << "o ";
      else
        std::cout << "  ";
    }
    std::cout << "|" << std::endl;
  }
  // for (int i = 0; i < cols; i++)
  //   std::cout << "---";
  std::cout << "\n\n";
}
vvi Solution::input()
{
  int rows, cols;
  std::cout << "Enter rows: ";
  std::cin >> rows;
  std::cout << "Enter cols: ";
  std::cin >> cols;
  std::cout << "Enter the board: " << std::endl;
  vvi board(rows);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int x;
      std::cin >> x;
      board[i].push_back(x);
    }
  }
  return board;
}
void Solution::gameOfLife()
{
  vvi nextGen = input();
  vvi genX;
  int row = nextGen.size();
  int column = nextGen[0].size();
  int generations = 0;
  do
  {
    states.insert(nextGen);
    std::this_thread::sleep_for(std::chrono::microseconds(500000));
    std::cout << "Generation: " << generations << std::endl;
    printBoard(nextGen);
    genX = nextGen;
    for (int r = 0; r < row; r++)
    {
      for (int c = 0; c < column; c++)
      {
        int neighbour = neighbours(genX, r, c);
        if (neighbour == 3)
          nextGen[r][c] = 1;
        else if (neighbour < 2)
          nextGen[r][c] = 0;
        else if (neighbour > 3)
          nextGen[r][c] = 0;
      }
    }
    generations++;
  } while (generations <= 50 && genX != nextGen && (states.find(genX) != states.end()));
}

int main()
{
  Solution s;
  s.gameOfLife();
  return 0;
}