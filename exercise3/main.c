#include "main.h"

int main(void) {
    char playAgain;
    int secretNumber; // declare a variable to hold the number to guess
    int guess;       // declare a variable to hold the user's guess
    int numGuesses = 0;

    srandom((unsigned int)time(NULL)); // set the random seed
    secretNumber = (random() % MAX_NUM) + 1; // ensure the number is at least 1 and at most 100 

    puts("Welcome to the number guessing game");

    while (playAgain != 'n' || playAgain != 'N') {
        printf("Please guess a number between %d and %d (0 to exit): ", MIN_NUM, MAX_NUM);
        int success = scanf("%d", &guess);

        if (!success) {
            puts("Invalid input. Input must be an integer number. Try again...\n");
            while (getchar() != '\n');
            continue;
        } else if (guess < MIN_NUM || guess > MAX_NUM) {
            puts("Guess out of range. Try again...\n");
            continue;
        }

        if (guess < secretNumber) {
            puts("Too low, please try again!\n");
        } else if (guess > secretNumber) {
            puts("Too high, please try again!\n");
        } else {
            printf("You got it! The correct number was %d and it only took you %d guesses!\n", secretNumber, numGuesses);

            printf("Do you want to play again? (y/n) ");
            while(getchar() != '\n');
            scanf("%c", &playAgain);

            if (playAgain == 'y' || playAgain == 'Y') {
                secretNumber = (random() % MAX_NUM) + 1;
                guess = -1;
            } else {
                puts("Thanks for playing!");
                break;
            }
        }

        numGuesses++;
    }


    return 0;
}
