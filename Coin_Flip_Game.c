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



//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>

//int main() {
//    long long total_points;
//    long long points_in_circle = 0;
//    double x, y;
//    double pi_estimate;

    // Seed the random number generator
//    srand(time(NULL));

//    printf("Enter the number of simulation points (e.g., 1000000): ");
//    scanf("%lld", &total_points);

//    if (total_points <= 0) {
//        printf("Number of points must be positive.\n");
//        return 1;
//    }

//    for (long long i = 0; i < total_points; i++) {
        // Generate random x and y coordinates between 0 and 1
//        x = (double)rand() / RAND_MAX;
//        y = (double)rand() / RAND_MAX;

        // Check if the point is within the unit circle (radius 1)
        // Distance from origin: sqrt(x^2 + y^2). If distance <= 1, it's in the circle.
        // Squaring both sides avoids sqrt for performance: x^2 + y^2 <= 1^2
//        if ((x * x) + (y * y) <= 1.0) {
//            points_in_circle++;
//        }
//    }

    // Calculate Pi: (points_in_circle / total_points) = (Area_circle / Area_square)
    // Area_circle = pi * r^2. For a unit square with inscribed circle, r=1.
    // Area_square = side^2. For a 1x1 square, side=1.
    // So, points_in_circle / total_points = (pi * 1^2) / 1^2 = pi
    // Therefore, pi_estimate = 4 * (points_in_circle / total_points)
//   pi_estimate = 4.0 * ((double)points_in_circle / total_points);

//    printf("Estimated value of PI: %lf\n", pi_estimate);

//    return 0;
//}
