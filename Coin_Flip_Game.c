#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, flip, score = 0, rounds = 0;
    char playAgain;

    //random number choose karne ke liye jaise python mein karte the 
    srand(time(0));

    printf("=== Welcome to the Coin Flip Game ===\n");

    do {
        printf("\nChoose:\n1. Heads\n2. Tails\nEnter your choice: ");
        scanf("%d", &choice);

        // Agar 1 aaya then it's Heads agar 2 aaya then it's Tails)
        flip = (rand() % 2) + 1;

        printf("Coin is flipping...\n");
        if (flip == 1) {
            printf("Result: Heads\n");
        } else {
            printf("Result: Tails\n");
        }

        if (choice == flip) {
            printf("Yay...You Win!\n");
            score++;
        } else {
            printf("Sorry...You Lose!\n");
        }

        rounds++;

        printf("Score: %d/%d\n", score, rounds);

        //Next round ke liye input 
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! Final Score: %d/%d\n", score, rounds);

    return 0;
}
