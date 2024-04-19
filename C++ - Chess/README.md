# Chess Game in C++

## Introduction

This is a chess game implemented in C++. The game is played between two players, and the objective is to checkmate the opponent's king. The game is played on an 8x8 board, with each player controlling 16 pieces. The pieces are:

* King
* Queen
* Rook
* Bishop
* Knight
* Pawn

Each piece has its own unique move set. The king can move one square in any direction. The queen can move any number of squares in any direction. The rook can move any number of squares horizontally or vertically. The bishop can move any number of squares diagonally. The knight can move two squares in one direction, then one square perpendicular to that direction. The pawn can move one square forward, or two squares forward on its first move. Pawns can also capture pieces diagonally.

## Code Explanation

The code for the chess game is divided into several files:

* `Chess.cpp`: This file contains the main function and the implementation of the `Chess` class. The `Chess` class represents the chess board and the pieces.
* `Game Files/Driver.cpp`: This file contains the main function for the game.
* `Game Files/Player1.cpp`: This file contains the implementation of the `Player1` class. The `Player1` class represents the first player.
* `Game Files/Player2.cpp`: This file contains the implementation of the `Player2` class. The `Player2` class represents the second player.

The `Chess` class contains the following methods:

* `Chess()`: The constructor for the `Chess` class.
* `display()`: This method displays the chess board.
* `gameOver()`: This method checks if the game is over.
* `setBoard()`: This method sets the chess board.
* `getBoard()`: This method gets the chess board.

The `Player1` and `Player2` classes contain the following methods:

* `Player1()`: The constructor for the `Player1` class.
* `Player2()`: The constructor for the `Player2` class.
* `turn()`: This method gets the player's move.

The main function of the program creates a `Chess` object and then calls the `display()` method to display the chess board. The main function then enters a loop, which continues until the game is over
