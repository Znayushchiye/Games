#include <Game.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

Game::Game()
{
  _TYPE_ board(9);
  for (int i = 0; i < 9; i++)
  {
    std::vector<int> column(9, 0);
    board[i] = column;
  }

  std::string str;
__INPUT__:
  std::cout << "Make random board?(y/n): ";
  std::cin >> str;
  if (str[0] == 'y' || str[0] == 'Y')
  {
    inputRandom(board);
  }
  else if (str[0] == 'n' || str[0] == 'N')
  {
    input(board);
  }
  else
  {
    std::cout << "Wrong Input! Enter Again.\n";
    goto __INPUT__;
  }
  autoSolve(board);
}

bool Game::isValid(_TYPE_ &board)
{
  // Check rows.
  for (int row = 0; row < 9; row++)
  {
    int arr[9] = {0};
    // Map values
    for (int col = 0; col < 9; col++)
    {
      arr[board[row][col] - 1]++;
    }

    // Check if each value comes exactly once
    for (int i = 0; i < 9; i++)
    {
      if (arr[i] != 1)
      {
        return false;
      }
    }
  }

  // Check columns.
  for (int col = 0; col < 9; col++)
  {
    // Map values
    int arr[9] = {0};
    for (int row = 0; row < 9; row++)
    {
      arr[board[row][col] - 1]++;
    }

    // Check if each value comes exactly once
    for (int i = 0; i < 9; i++)
    {
      if (arr[i] != 1)
      {
        return false;
      }
    }
  }

  // Check subgrids.
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int arr[9] = {0};
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          arr[board[i * 3 + k][j * 3 + l] - 1]++;
        }
      }

      // Check if each value comes exactly once
      for (int x = 0; x < 9; x++)
      {
        if (arr[x] != 1)
        {
          return false;
        }
      }
    }
  }
  return true;
}

void Game::printBoard(_TYPE_ &board)
{
  for (int i = 0; i < 9; i++)
  {
    if (i % 3 == 0)
    {
      std::cout << "|-----------------------|\n";
    }
    std::cout << "| ";
    for (int j = 0; j < 9; j++)
    {
      if (j != 0 && j % 3 == 0)
      {
        std::cout << "| ";
      }
      std::cout << board[i][j] << " ";
    }
    std::cout << "|\n";
  }
  std::cout << "|-----------------------|\n";
}

void Game::input(_TYPE_ &board)
{
__ENTER_AGAIN__:
  std::cout << "Enter the 9x9 Sudoku board: \n";
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      std::cin >> board[i][j];
    }
  }

  if (isValid(board))
  {
    printBoard(board);
  }
  else
  {
    std::cout << "Invalid Board! Enter again.\n";
    goto __ENTER_AGAIN__;
  }
}

void Game::rowShuffle(_TYPE_ &board, const int &offset)
{
  int row1 = offset + rand() % 3;
  int row2 = offset + rand() % 3;
  std::swap(board[row1], board[row2]);
}

void Game::colShuffle(_TYPE_ &board, const int &offset)
{
  int col1 = offset + rand() % 3;
  int col2 = offset + rand() % 3;
  for (int i = 0; i < 9; i++)
  {
    std::swap(board[i][col1], board[i][col2]);
  }
}

void Game::inputRandom(_TYPE_ &board)
{
  // Creating a fixed Sudoku board.
  for (int r = 0; r < 9; r++)
  {
    for (int c = 0; c < 9; c++)
    {
      // int square = ((r / 3) + (c / 3)) + (2 * (c / 3));
      int num = (r * 3 + r / 3 + c) % 9 + 1;
      board[r][c] = num + 1;
    }
  }

  srand(time(0));
  int swapNumber = rand() % 10;

  // Swapping random rows and columns a swapNumber times in a grid to fully randomize the sudoku.
  for (int i = 0; i < 2 * swapNumber; i++)
  {
    int rowOrCol = rand() % 2;
    int option = rand() % 3;
    switch (rowOrCol)
    {
    case 0: // Shuffle rows.
      switch (option)
      {
      case 0: // Shuffle among rows 0 to 2, both inclusive.
        rowShuffle(board, 0);
        break;
      case 1: // Shuffle among rows 3 to 5, both inclusive.
        rowShuffle(board, 3);
        break;
      case 2: // Shuffle among rows 6 to 8, both inclusive.
        rowShuffle(board, 6);
        break;
      }
      break;
    case 1: // Shuffle columns.
      switch (option)
      {
      case 0: // Shuffle among cols 0 to 2, both inclusive.
        colShuffle(board, 0);
        break;
      case 1: // Shuffle among cols 3 to 5, both inclusive.
        colShuffle(board, 3);
        break;
      case 2: // Shuffle among cols 6 to 8, both inclusive.
        colShuffle(board, 6);
        break;
      }
      break;
    }
  }
}

void Game::autoSolve(_TYPE_ &board)
{
  std::cout << "Solving the Sudoku board...\n";
  int row = -1, col = -1;
  bool isEmpty = true;
  for (int i = 0; i < 9 && isEmpty; i++)
  {
    for (int j = 0; j < 9 && isEmpty; j++)
    {
      if (board[i][j] == 0)
      {
        row = i;
        col = j;
        isEmpty = false;
      }
    }
  }

  if (isEmpty)
  {
    std::cout << "Solved!\n";
    printBoard(board);
    return;
  }

  for (int num = 1; num <= 9; num++)
  {
    board[row][col] = num;
    if (isValid(board))
    {
      autoSolve(board);
    }
    board[row][col] = 0;
  }
}