#include <stdio.h>
#include <stdlib.h>
#include "train.h"
#include "string.h"

int main()
{
    List w=NULL;
    int choice;

    do {

        do {

        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a locomotive\n");
        printf("2. Add a wagon\n");
        printf("3. Search for a wagon\n");
        printf("4. Display the content of the train\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);


        if (choice < 1 || choice > 5) printf("Invalid choice! Please enter a number between 1 and 5.\n");

         } while (choice < 1 || choice > 5);


        switch (choice) {
            case 1: {
                w=add_locomotive_head(w);

                break;
            }

            case 2: {
                w=add_wagon_tail(w);
                break;
            }

            case 3: {
                int number;

                printf("Enter the number of the wagon to search for: \n"); scanf("%d", &number);
                if (search_wagon(w, number)==1) printf("Wagon found! \n");
                else printf("Wagon not found! \n");

                break;
            }

            case 4: {
                display_train(w);
                break;
            }

            case 5: {
                printf("Thank you for using this program!\n");
                free(w);
                break;
            }

        }

    } while (choice != 5);

    return 0;
}

