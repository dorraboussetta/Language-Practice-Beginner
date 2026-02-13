#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Traveler.h"

int main() {
    int choice, n;
    Traveler *tab=Load_data("Traveler.bin", &n);

    do {

    choice=menu();

        switch (choice) {
            case 1: {
                Traveler t;
                enterTraveler(&t);
                tab=add(t, tab, &n);
                break;
            }

            case 2: {
                char id[10];
                printf("Enter the id of the traveler you want to find.\n");
                fflush(stdin); gets(id);
                int pos=find_traveler(tab, id, n);
                if (pos!=-1)printf("Traveler found!\n");
                else printf("Traveler not found.\n");

                break;
            }

            case 3: {
                char id[10];
                printf("Enter the id of the traveler you want to delete.\n");
                fflush(stdin); gets(id);
                delete_traveler(tab, id, &n);
                break;
            }



            case 4: {
                display_travelers(tab, n);
                break;
            }
            case 5: {
                save_data("Traveler.bin", tab, n);
                release(tab);
                break;
            }

        }

    } while (choice != 5);

    return 0;
}


