#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
class Solution
{
private:
  int neighbours(vector<vector<int>> &board, int r, int c)
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
  void printBoard(const vector<vector<int>> &board)
  {
    for (auto row : board)
    {
      for (auto cell : row)
      {
        cout << cell << " ";
      }
      cout << endl;
    }
    cout << "\n\n";
  }

public:
  void gameOfLife(vector<vector<int>> &board)
  {
    vector<vector<int>> nextGen = board;
    vector<vector<int>> genX;
    int row = board.size();
    int column = board[0].size();
    int generations = 0;
    do
    {
      std::this_thread::sleep_for(std::chrono::microseconds(500000));
      system("cls");
      cout << "Generation: " << generations << endl;
      printBoard(nextGen);
      genX = nextGen;
      for (int r = 0; r < row; r++)
      {
        for (int c = 0; c < column; c++)
        {
          int neighbour = neighbours(genX, r, c);
          // int neighbour = neighbours(board, r, c);
          if (neighbour == 3)
          {
            nextGen[r][c] = 1;
          }
          else if (neighbour < 2)
          {
            nextGen[r][c] = 0;
          }
          else if (neighbour > 3)
          {
            nextGen[r][c] = 0;
          }
        }
        generations++;
      }
    } while (generations <= 50 && genX != nextGen);
  }
};

int main()
{
  int rows, cols;
  cout << "Enter rows: ";
  cin >> rows;
  cout << "Enter cols: ";
  cin >> cols;
  cout << "Enter the board: " << endl;
  vector<vector<int>> board(rows);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int x;
      cin >> x;
      board[i].push_back(x);
    }
  }
  Solution s;
  s.gameOfLife(board);
  return 0;
}