#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*This program is an interactive guessing game with three difficulty levels.
Depending on the chosen level, the player must guess a random number (and a letter in level 3) within a limited number of attempts.
The game provides hints after each guess and ends when the player wins or runs out of attempts.*/

int main()
{   int level,guess, attempts;
    char guess_letter;

    srand(time(NULL));
    do {
        printf("***** Main menu for the game *****\n");
        printf("1- to choose level 1\n");
        printf("2- to choose level 2\n");
        printf("3- to choose level 3\n");
        printf("0- to quit the game\n");

        do {
            printf("Choose a level(1,2,3,0): \n");
            scanf("%d", &level);

        } while (level<0 || level>3);

        printf("%d", level);

        if (level ==0)
        {printf("Thank you for playing! \n"); break;}

        if (level == 1){
            attempts=15;
            printf("The mystery is a number between 0 and 100 \n");
            int r = rand() % 101;
            printf("Guess the number: \n");

            do {
                    scanf("%d", &guess);
                    attempts-=1;
                    if (guess==r)
                    { printf("You win after %d attempts!\n", 15-attempts);
                    }
                    else if (guess>r) printf("It's lower. %d attempts remaining.\n", attempts);
                    else if (guess<r) printf("It's higher. %d attempts remaining.\n", attempts);

            } while (r!=guess && attempts!=0);


        }

            if (level == 2){
            printf("The mystery is a number between 0 and 10000 \n");
            attempts=10;
            int r = (rand() % 10000) +1;
            printf("Guess the number: \n");

            do {
                    scanf("%d", &guess);
                    attempts-=1;
                    if (guess==r)
                    { printf("You win after %d attempts!\n", 10-attempts);
                    }
                    else if (guess>r) printf("It's lower. %d attempts remaining.\n", attempts);
                    else if (guess<r) printf("It's higher. %d attempts remaining.\n", attempts);

            } while (r!=guess && attempts!=0);
        }

            if (level == 3){
            attempts=10;
            printf("The mystery is a number between 10 and 100 \n");
            printf("The mystery is also an uppercase letter \n");
            int r = rand() % 91 + 10;
            char letter='A' + rand() % 26;
            guess=-1; guess_letter='*';
            int guessed_letter=0, guessed_number=0;


            do {


                    if (guess!=r){
                         printf("Guess the number:\n"); scanf("%d", &guess);
                    }
                    if (guess_letter!=letter) {
                        printf("Guess the letter:\n");scanf(" %c", &guess_letter);
                    }
                    attempts--;
                    if (guess==r  && guess_letter==letter) printf("Congrats! You guessed both correctly after %d attempts!\n", 10-attempts);




                    if (guess>r) printf("The number's lower. %d attempts remaining.\n", attempts);
                    else {if (guess<r)
                         printf("The number's higher. %d attempts remaining.\n", attempts);
                         else {
                            if (guessed_number==0) printf("Congrats! You guessed the number after %d attempts!\n", 10-attempts);
                            else guessed_number=1;
                            }
                             }


                    if (letter>guess_letter) printf("The letter's after. %d attempts remaining.\n", attempts);
                    else {if (letter<guess_letter) printf("The letter's before. %d attempts remaining.\n", attempts);
                          else {
                            if (guessed_letter==0)  printf("Congrats! You guessed the letter after %d attempts!\n", 10-attempts);
                            else guessed_letter=1;

                             }}




            } while ((r!=guess || letter!=guess_letter) && (attempts!=0));
                if (attempts == 0 && guess != r)
                printf("Out of attempts! The mystery number was %d.\n", r);

                if (attempts == 0 && guess_letter != letter)
                printf("Out of attempts! The mystery letter was %c.\n", letter);

        }

    } while (level!=0);

    return 0;
}
