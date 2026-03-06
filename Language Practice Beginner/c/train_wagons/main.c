#include <stdio.h>
#include <stdlib.h>
#include "train.h"
#include "string.h"

int main()
{
    List w=NULL;
    int choice;

    w=load_train(w, "train.txt");

    do {

        do {

        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a locomotive\n");
        printf("2. Add a wagon\n");
        printf("3. Search for a wagon\n");
        printf("4. Display the content of the train\n");
        printf("5. Delete the failed wagons\n");
        printf("6. Add a wagon after a wagon with a given number\n");
        printf("7. Quit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);


        if (choice < 1 || choice > 7) printf("Invalid choice! Please enter a number between 1 and 7.\n");

         } while (choice < 1 || choice > 7);


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
                w=delete_failed_wg(w);
                break;
            }
            case 6: {
                int number;
                printf("Enter the number of the wagon you want to add a wagon after:\n"); scanf("%d",&number);
                w=insert_wagon(w,number);
                break;
            }

            case 7: {
                printf("Thank you for using this program!\n");
                save_train(w, "train.txt");
                w=free_wagons(w);
                if (w==NULL) printf("Wagons freed!\n");
                else printf("Wagons not freed!\n");
                break;
            }

        }

    } while (choice != 7);

    return 0;
}

