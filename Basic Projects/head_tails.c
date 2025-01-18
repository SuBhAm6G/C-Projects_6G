#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include time.h for seeding the random function

#define MAX_TRIALS 100000 // Set a limit for the maximum number of trials

int main()
{
    int rerun = 1; // Variable to control the rerun option

    while (rerun) // Loop to rerun the code
    {
        int input_tosses; // Variable to store the number of tosses

        // Prompt the user to enter the number of tosses
        printf("Enter the number of times you want the trial to continue = ");
        scanf("%d", &input_tosses);

        // Check if the input exceeds the maximum allowed
        if (input_tosses > MAX_TRIALS)
        {
            printf("The input exceeds the limit \n");
            return 1; // Exit with an error code
        }

        int heads = 0; // Counter for heads
        int tails = 0; // Counter for tails
        int result[MAX_TRIALS]; // Array to store the results of each toss

        srand(time(0)); // Seed the random number generator

        // Simulate the coin tosses
        for (int i = 0; i < input_tosses; i++)
        {
            result[i] = rand() % 2; // Generate a random number (0 or 1)

            if (result[i] == 0) // If result is 0, it's a head
            {
                heads++; // Increment heads counter
            }
            else // If result is 1, it's a tail
            {
                tails++; // Increment tails counter
            }
        }

        // Calculate the probabilities
        double pheads = (double)heads / input_tosses;
        double ptails = (double)tails / input_tosses;

        // Print the probabilities
        printf("The probability of getting heads: %.3f \n", pheads);
        printf("The probability of getting tails: %.3f \n", ptails);

        // Ask the user if they want to rerun the simulation
        printf("Do you want to rerun? Press 0 for no & 1 for yes \n ");
        scanf("%d", &rerun); // Read the user's choice
    }

    return 0; // Exit the program successfully
}
