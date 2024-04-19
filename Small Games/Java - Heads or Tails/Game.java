import java.util.Scanner;

class Game {

  private static Scanner scanner = new Scanner(System.in);
  private static int flipsCount;
  private static int headsCount = 0;
  private static int tailsCount = 0;

  private static void inputFlips() {
    flipsCount = scanner.nextInt();
    while (flipsCount < 1) {
      System.out.print("Invalid input. Try again: ");
      flipsCount = scanner.nextInt();
    }
  }

  private static void flip() {
    inputFlips();
    for (int i = 0; i < flipsCount; i++) {
      int flip = (int) (Math.random() * 2);
      if (flipsCount > 1) System.out.print(i + 1 + ". ");
      if (flip == 0) {
        headsCount++;
        System.out.println("Heads");
      } else {
        tailsCount++;
        System.out.println("Tails");
      }
    }

    System.out.println("\nHeads: " + headsCount);
    System.out.println("Tails: " + tailsCount);
  }

  public static void main(String[] args) {
    System.out.println("---------------------------");
    System.out.println("Heads or Tails!");
    System.out.print("\nHow many flips?: ");
    flip();
    System.out.println("---------------------------");
    scanner.close();
  }
}
