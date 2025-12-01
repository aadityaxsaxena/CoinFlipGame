//Presenting you my project for Programming In C course titled "Coin Flip Game!". 
//Additionally you can also estimate the value of PI using this Coin Flip Game.
/* This Is Menu Driven Program where for The Coin Flip Game I have used rand() that generates a random number 
which on mudulo will either give 0 or 1 and if that matches with user input the user will win and the score will be updated */
/* Then for estimating the value of PI I studied the Monte Carlo Method and applied the same to my code
This calculates an approximate value of Pi using Monte Carlo Method:
1. Ask the user how many random points to use.
2. Generate that many points with random x and y values between 0 and 1.
3. Check each point to see if it falls inside the unit circle (x^2 + y^2 <= 1).
4. Use the formula Pi ≈ 4 * (number of points inside circle) / (total points) to estimate Pi.
5. Print the estimated value of Pi to the screen.*/
// Together all these features combines to create a completely fun and crazy program.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wins = 0;
int totalGames = 0;
void coinFlipGame() {
    int choice, flip;
    printf("\n---------------Welcome To Coin Flip Game---------------\n");
    printf("Choice Coin Side : 0 = Heads, 1 = Tails: ");
    scanf("%d", &choice);
    if (choice != 0 && choice != 1) {
        printf("Invalid choice! Choose 0 or 1\n");
        return;
    }
    flip = rand() % 2;
    printf("Coin Flipped: %s\n", flip == 0 ? "Heads" : "Tails");
    if (choice == flip) {
        printf("You Win The Round\n");
        wins++;
    } else {
        printf("You Lost The Round. Retry\n");
    }
    totalGames++;
}
void estimatePi() {
    int p;
    int InCircle = 0;
    double x, y;
    printf("\n---------------Estimate Pi---------------\n");
    printf("Enter number of random points: ");
    scanf("%d", &p);
    if (p <= 0) {
        printf("Number of points must be positive\n");
        return;
    }
    for (int i = 0; i < p; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            InCircle++;
        }
    }
    double pi = 4.0 * InCircle / p;
    printf("Estimated Pi using %d points: %.6lf\n", p, pi);
}
void showScorecard() {
    int lost = totalGames - wins;
    printf("\n---------------Game Scorecard---------------\n");
    printf("Total Games Played: %d\n", totalGames);
    printf("Total Wins: %d\n", wins);
    printf("Total Losses: %d\n", lost);
}
int main() {
    int choice;
    srand(time(0));
    do {
        printf("\n===============MENU===============\n");
        printf("1. Play Coin Flip Game\n");
        printf("2. Estimate Value Of PI Using Coin Flips\n");
        printf("3. Show Game Scorecard\n");
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
                printf("Exited\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 4);
    return 0;
}
