#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
// returns an n-digit random number
int randomNumber(int choice)
{
    int divisor = 1;
    for (int num = choice; num != 0; num--)
        divisor *= 10;
    int random = rand() % divisor;
    return random;
}
int main()
{
    int choice, enteredNumber, score = 0, random;

    cout << "----------------------------------------------";
    cout << "\nWelcome to the random number guessing game.";
    cout << "\nFirst choose the difficulty of the game.";
    cout << "\n\nChoose difficulty";
    cout << "\n1 : Easy (1 digit number)";
    cout << "\n2 : Medium (2 digit number)";
    cout << "\n3 : Hard (3 digit number)";
    cout << "\n4 : Painful (4 digit number)";
    cout << "\n5 : Deadly (5 digit number)";
    cout << "\nEnter choice :- ";

    cin >> choice;
    if (choice > 5 || choice < 1)
    {
        cout << "\nWrong choice!";
        return 0;
    }

    srand(time(0));
    random = randomNumber(choice);
    do
    {
        cout << "\nEnter your guess:";
        cin >> enteredNumber;
        score++;
        if (enteredNumber > random)
            cout << "(Psst, go lower.)" << endl;
        else
            cout << "(Psst, go higher.)" << endl;
    } while (enteredNumber != random);

    cout << "You guessed it!" << endl;
    cout << "Score:" << score;
    return 0;
}
