//CoinFlipGame with Estimating value of PI using coin flips.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wins = 0;
int totalGames = 0;
void coinFlipGame() {
    int guess, flip;
    printf("\n--- Coin Flip Game ---\n");
    printf("Guess the coin: 0 = Heads, 1 = Tails: ");
    scanf("%d", &guess);
    if (guess != 0 && guess != 1) {
        printf("Invalid choice! Choose 0 or 1.\n");
        return;
    }
    flip = rand() % 2;
    printf("Coin flipped: %s\n", flip == 0 ? "Heads" : "Tails");
    if (guess == flip) {
        printf("You guessed it right!\n");
        wins++;
    } else {
        printf("Wrong guess. Try again!\n");
    }
    totalGames++;
}
void estimatePi() {
    int points;
    int insideCircle = 0;
    double x, y;
    printf("\n--- Estimate Pi ---\n");
    printf("Enter number of random points: ");
    scanf("%d", &points);
    if (points <= 0) {
        printf("Number of points must be positive!\n");
        return;
    }
    for (int i = 0; i < points; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            insideCircle++;
        }
    }
    double pi = 4.0 * insideCircle / points;
    printf("Estimated Pi using %d points: %.6lf\n", points, pi);
}
void showScorecard() {
    printf("\n--- Scorecard ---\n");
    printf("Total games played: %d\n", totalGames);
    printf("Total correct guesses: %d\n", wins);
    if (totalGames > 0) {
        double percent = (double)wins / totalGames * 100;
        printf("Winning percentage: %.2lf%%\n", percent);
    }
}
int main() {
    int choice;
    srand(time(0));
    do {
        printf("\n=== MENU ===\n");
        printf("1. Play Coin Flip Game\n");
        printf("2. Estimate Pi using Monte Carlo\n");
        printf("3. Show Scorecard\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                coinFlipGame();
                break;
            case 2:
                estimatePi();
                break;
            case 3:
                showScorecard();
                break;
            case 4:
                printf("Exiting program. Bye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
