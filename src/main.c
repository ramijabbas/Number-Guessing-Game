#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;
    int attempts = 0, maxAttempts;
    int minRange = 1, maxRange;
    int difficulty;
    int playAgain;
    int score = 100;

    srand(time(NULL));

    do {
        attempts = 0;
        score = 100;

        printf("\n====================================\n");
        printf("     NUMBER GUESSING GAME IN C\n");
        printf("====================================\n");

        printf("\nChoose Difficulty:\n");
        printf("1. Easy   (1 - 50,  10 attempts)\n");
        printf("2. Medium (1 - 100, 7 attempts)\n");
        printf("3. Hard   (1 - 500, 5 attempts)\n");

        printf("\nEnter your choice: ");
        scanf("%d", &difficulty);

        if (difficulty == 1) {
            maxRange = 50;
            maxAttempts = 10;
        } 
        else if (difficulty == 2) {
            maxRange = 100;
            maxAttempts = 7;
        } 
        else if (difficulty == 3) {
            maxRange = 500;
            maxAttempts = 5;
        } 
        else {
            printf("\nInvalid choice! Medium mode selected by default.\n");
            maxRange = 100;
            maxAttempts = 7;
        }

        secretNumber = rand() % maxRange + 1;

        printf("\nI have selected a number between %d and %d.\n", minRange, maxRange);
        printf("You have %d attempts.\n", maxAttempts);

        while (attempts < maxAttempts) {
            printf("\nAttempt %d/%d", attempts + 1, maxAttempts);
            printf("\nEnter your guess: ");
            scanf("%d", &guess);

            if (guess < minRange || guess > maxRange) {
                printf("Please enter number between %d and %d.\n", minRange, maxRange);
                continue;
            }

            attempts++;

            if (guess == secretNumber) {
                printf("\nCongratulations! You guessed the number!\n");
                printf("Secret Number was: %d\n", secretNumber);
                printf("Attempts used: %d\n", attempts);

                score = score - (attempts - 1) * 10;

                if (score < 0) {
                    score = 0;
                }

                printf("Your Score: %d\n", score);

                if (attempts == 1) {
                    printf("Amazing! First try!\n");
                } 
                else if (attempts <= 3) {
                    printf("Great guessing!\n");
                } 
                else {
                    printf("Good job!\n");
                }

                break;
            } 
            else if (guess > secretNumber) {
                printf("Too High!\n");

                if (guess - secretNumber <= 5) {
                    printf("Hint: You are very close!\n");
                }
            } 
            else {
                printf("Too Low!\n");

                if (secretNumber - guess <= 5) {
                    printf("Hint: You are very close!\n");
                }
            }

            if (attempts == maxAttempts - 2) {
                if (secretNumber % 2 == 0) {
                    printf("Extra Hint: The number is even.\n");
                } else {
                    printf("Extra Hint: The number is odd.\n");
                }
            }

            printf("Remaining attempts: %d\n", maxAttempts - attempts);
        }

        if (attempts == maxAttempts && guess != secretNumber) {
            printf("\nGame Over!\n");
            printf("You could not guess the number.\n");
            printf("Correct number was: %d\n", secretNumber);
            printf("Your Score: 0\n");
        }

        printf("\nDo you want to play again?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter choice: ");
        scanf("%d", &playAgain);

    } while (playAgain == 1);

    printf("\nThanks for playing!\n");

    return 0;
}