import java.util.Scanner;

public class Game {

  private static int randomNumber(int choice) {
    int divisor = 1;
    for (int num = choice; num != 0; num--) divisor *= 10;
    int random = (int) (Math.random() * divisor);
    return random;
  }

  public static void main(String[] args) {
    int choice, enteredNumber, score = 0, random;

    System.out.println("----------------------------------------------");
    System.out.println("Welcome to the random number guessing game.");
    System.out.println("First choose the difficulty of the game.");
    System.out.println("\nChoose difficulty");
    System.out.println("1 : Easy (1 digit number)");
    System.out.println("2 : Medium (2 digit number)");
    System.out.println("3 : Hard (3 digit number)");
    System.out.println("4 : Painful (4 digit number)");
    System.out.println("5 : Deadly (5 digit number)");
    System.out.println("\nEnter choice :- ");

    Scanner scanner = new Scanner(System.in);
    choice = scanner.nextInt();
    while (choice < 1 || choice > 5) {
      System.out.println(
        "Invalid choice. Please enter a valid difficulty (1-5): "
      );
      choice = scanner.nextInt();
    }

    System.out.println("You have chosen difficulty " + choice);

    random = randomNumber(choice);

    System.out.println("Guess the number :- ");
    while (true) {
      enteredNumber = scanner.nextInt();
      if (enteredNumber == random) {
        System.out.println("You guessed the number correctly!");
        System.out.println("Your score is " + score);
        break;
      } else {
        System.out.println("You guessed the number incorrectly!");
        if (enteredNumber < random) {
          System.out.println("(Psst, go higher.)");
        } else {
          System.out.println("(Psst, go lower.)");
        }
        System.out.println("Try again :- ");
        score++;
      }
    }
    scanner.close();
  }
}
