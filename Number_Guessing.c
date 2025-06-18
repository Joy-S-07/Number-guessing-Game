#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessNumber(int randomNumber, int guess, int attempts, int min, int max) {
    if (guess < min || guess > max) {
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        return 1;
    }
    if (guess < randomNumber) {
        printf("Higher Please! Try again.\n");
        return 1;
    } else if (guess > randomNumber) {
        printf("Lower Please! Try again.\n");
        return 1;
    } else {
        printf("Congratulations! You've guessed the number at %dth Attempt!\n", attempts);
        return 0;
    }
}

int main() {
    int min = 1, max = 100;
    srand(time(NULL));
    int randomNumber = min + rand() % (max - min + 1);
    int attempts = 1;
    int guess = 0;
    int result;
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between %d and %d. Can you guess it?\n", min, max);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        result = guessNumber(randomNumber, guess, attempts, min, max);
        attempts++;
    } while(result == 1); //

    return 0;
}