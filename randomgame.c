#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int calculateNumberOfGuesses(int range)
{
    return (int)ceil(log2(range)); 
}

int main()
{
    int min;
    int max;
    int guess;
    int numberOfGuessesUsed = 0;
    int randomAnswer;
    int numberOfGuesses;
    char ready;
    int range;

    printf("\nDo you want to start game now, y/n\n");
    printf("Enter \'y\' to continue of \'n\' to quit: ");
    scanf(" %c", &ready);

    if (ready == 'n')
    {
        printf("Game has ended");
    }
    else if (ready == 'y'){

        printf("\n Enter the minimum number: ");
        scanf("%d", &min);

        printf("\n Enter the maximum number: ");
        scanf("%d", &max);

        range = max - min;
        numberOfGuesses = calculateNumberOfGuesses(range);

        printf("You have only %d guesses", numberOfGuesses);

        srand(time(0));
        randomAnswer = (rand() % range) + min;

        //printf("\n%d\n", randomAnswer);

        do
        {
            printf("\nEnter a random nummber from %d to %d: ", min, max);
            scanf("%d", &guess);

            if (guess < min || guess > max)
            {
                printf("\nInvalid number, number must be from %d to %d", min, max);
                continue;
            }
            

            if (guess > randomAnswer)
            {
                printf("\n*******************************\n");
                printf("\nSmaller than that, take another guess\n");
                printf("\n*******************************\n");
            }
            else if (guess < randomAnswer)
            {
                printf("\n*******************************\n");
                printf("Bigger, than that, take another guess\n");
                printf("\n*******************************\n");
            }
            else
            {
                printf("\n*******************************\n");
                printf("Great\n");
                printf("You got it after %d guess(es)", numberOfGuessesUsed + 1);
                printf("\n*******************************\n");

                return 0;
            }
            numberOfGuessesUsed++;
            if (numberOfGuessesUsed == numberOfGuesses){
                printf("\n*******************************\n");
                printf("Maximum number of guesses reached\n");
                printf("Try again");
                printf("\n*******************************\n");
            }
        } while (numberOfGuessesUsed < numberOfGuesses);

        

        return 0;
    }
    else {
        printf("\n*******************************\n");
        printf("\nInvalid choice\n");
        printf("\n*******************************\n");
    }
    
}
