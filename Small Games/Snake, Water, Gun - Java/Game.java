import java.util.Scanner;

public class Game {

  private static String map = "swg";
  private static Scanner scanner = new Scanner(System.in);
  private static int gameCount;
  private static int score = 0;

  private static int rng() {
    return (int) (Math.random() * 3);
  }

  private static int userInput() {
    System.out.println("Enter your choice (s/w/g)");

    char userChoice = scanner.next().charAt(0);
    while (!(userChoice == 's' || userChoice == 'w' || userChoice == 'g')) {
      System.out.println("Invalid input");
      userChoice = scanner.next().charAt(0);
    }
    return map.indexOf(userChoice);
  }

  private static void game() {
    int userMove, compMove;
    System.out.print("Enter the number of games you want to play: ");
    gameCount = scanner.nextInt();
    while (gameCount > 0) {
      userMove = userInput();
      compMove = rng();
      if (userMove - compMove == 1) {
        score--;
        System.out.println("You lost this round!");
      } else if (userMove - compMove == -1) {
        score++;
        System.out.println("You won this round!");
      } else if (userMove - compMove == 2) {
        score--;
        System.out.println("You lost this round!");
      } else if (userMove - compMove == -2) {
        score--;
        System.out.println("You lost this round!");
      } else {
        System.out.println("It's a draw!");
      }
      gameCount--;
    }
    System.out.println("\n");
    if (score > 0) {
      System.out.println("You won the game by " + score + " points!");
    } else if (score < 0) {
      System.out.println(
        "You lost the game by " + Math.abs(score) + " points."
      );
    } else {
      System.out.println("It's a draw!");
    }
  }

  public static void main(String[] args) {
    System.out.println(
      "------------------------------------------------------------\n"
    );
    System.out.println("Welcome to Tic Tac Toe!\n");
    game();
    System.out.println(
      "------------------------------------------------------------\n"
    );
  }
}
