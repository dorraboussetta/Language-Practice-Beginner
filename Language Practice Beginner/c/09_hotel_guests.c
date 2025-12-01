#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This program manages a small list of event participants, including their ID, personal information, meal choices, and hotel preferences.
It allows adding participants, calculating individual invoices, displaying participants based on selected criteria, and deleting a participant by ID.
The program runs through a menu system until the user chooses to quit.*/

typedef struct part {
    char meals[2][10];
    int hotel_type;
    char id[10];
    char last_name[10];
    char first_name[10];


}participant;

int main() {
    int choice;
    int num_guests=0;
    participant guests[10];

    for (int index=0; index<10; index++) {
        strcpy(guests[index].meals[0],"");
        strcpy(guests[index].meals[1],"");
    }



    do {
        // Display the menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a participant \n");
        printf("2. Calculate the amount of the invoice for a participant\n");
        printf("3. Display the information of the participants\n");
        printf("4. Delete a participant given by his/her ID\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
            continue;
        }

        // Execute based on user choice
        switch (choice) {
            case 1: {
                int answer;
                num_guests++;
                printf("Enter the id of the participant: \n"); fflush(stdin); gets(guests[num_guests-1].id);
                printf("Enter the first name of the participant: \n"); gets(guests[num_guests-1].first_name);
                printf("Enter the last name of the participant: \n"); gets(guests[num_guests-1].last_name);

                do {
                    printf("Do you want lunch? Please enter 1 for yes and 0 for no: \n"); scanf("%d", &answer);

                } while (answer!=0 && answer!=1);

                if (answer==1) strcpy(guests[num_guests-1].meals[0], "lunch");

                do {
                        printf("Do you want dinner? Please enter 1 for yes and 0 for no: \n"); scanf("%d", &answer);

                    } while (answer!=0 && answer!=1);


                if (answer==1) strcpy(guests[num_guests-1].meals[1], "dinner");


                do {
                printf("Enter the type of hotel you want. Please enter 4 or 5. If you don't want a hotel, enter 0: \n"); scanf("%d", &guests[num_guests-1].hotel_type);
                } while (guests[num_guests-1].hotel_type!=0 && guests[num_guests-1].hotel_type!=4 && guests[num_guests-1].hotel_type!=5);



                break;}


            case 2: {

                int invoice=0, index=0;
                char identity[10];

                printf("Enter the id of the guest you want the invoice of: \n"); fflush(stdin); gets(identity);

                while (index<=num_guests-1  && strcmp(guests[index].id, identity)!= 0) {
                    index++;
                }

                if (index>num_guests-1) printf("Error. There is no guest with such id\n");
                else {
                    if (strcmp(guests[index].meals[0], "lunch")==0) invoice+=15;
                    if (strcmp(guests[index].meals[1], "dinner")==0) invoice+=35;

                    if (guests[index].hotel_type==4) invoice+=75;
                    else if (guests[index].hotel_type==5) invoice+=100;

                printf("The invoice for guest number %d is %d\n", index, invoice);

                invoice=0;

                }






                break;
            }

            case 3: {

               int selection, found;

               do {
                    printf("\nDo you want to display:\n");
                    printf("1. All participants\n");
                    printf("2. The participants who chose a 4 stars hotel\n");
                    printf("3. The participants who chose a 5 stars hotel\n");
                    scanf("%d", &selection);

               }while (selection<1 || selection>3);

               if (selection==1) {
                    for (int index=0; index<num_guests; index++) {
                        printf("For guest %d:\n", index+1);
                        printf("ID: %s\n", guests[index].id);
                        printf("First name: %s\n", guests[index].first_name);
                        printf("Last name: %s\n", guests[index].last_name);
                        printf("Meal choice: \n");
                        if (strlen(guests[index].meals[0])!=0) printf("Lunch.\n"); else printf("No lunch. \n");
                        if (strlen(guests[index].meals[1])!=0) printf("Dinner.\n"); else printf("No dinner. \n");
                        if (guests[index].hotel_type==0) printf("NO hotel. \n"); else printf("%d stars hotel.\n", guests[index].hotel_type);

                    }
               }
                    else if (selection==2) {
                        for (int index=0; index<num_guests; index++) {
                            if (guests[index].hotel_type==4) {
                                    found=1;
                                    printf("For guest %d:\n", index+1);
                                    printf("ID: %s\n", guests[index].id);
                                    printf("First name: %s\n", guests[index].first_name);
                                    printf("Last name: %s\n", guests[index].last_name);
                                    printf("Meal choice: \n");
                                    if (strlen(guests[index].meals[0])!=0) printf("Lunch.\n"); else printf("No lunch. \n");
                                    if (strlen(guests[index].meals[1])!=0) printf("Dinner.\n"); else printf("No dinner. \n");
                                    if (guests[index].hotel_type==0) printf("NO hotel. \n"); else printf("%d stars hotel.\n", guests[index].hotel_type);


                            }
                        }
                        if (found==0) printf("No guests chose a 4 stars hotel\n"); }

                    else if (selection==3) {
                            for (int index=0; index<num_guests; index++) {
                            if (guests[index].hotel_type==5) {
                                    found=1;
                                    printf("For guest %d:\n", index+1);
                                    printf("ID: %s\n", guests[index].id);
                                    printf("First name: %s\n", guests[index].first_name);
                                    printf("Last name: %s\n", guests[index].last_name);
                                    printf("Meal choice: \n");
                                    if (strlen(guests[index].meals[0])!=0) printf("Lunch.\n"); else printf("No lunch. \n");
                                    if (strlen(guests[index].meals[1])!=0) printf("Dinner.\n"); else printf("No dinner. \n");
                                    if (guests[index].hotel_type==0) printf("NO hotel. \n"); else printf("%d stars hotel.\n", guests[index].hotel_type);


                            }


                    }
                        if (found==0) printf("No guests chose a 5 stars hotel\n"); }







                break;
            }

            case 4: {

                int index=0;
                char identity[10];

                printf("Enter the id of the guest you want delete: \n"); fflush(stdin); gets(identity);

                while (index<=num_guests-1  && strcmp(guests[index].id, identity)!= 0) {
                    index++;
                }

                if (index>num_guests-1) printf("Error. There is no guest with such id\n");
                else {
                        for (int guest=index; guest<num_guests-1; guest++) {
                            guests[guest]=guests[guest+1];
                        }


                }




                break;
            }

            case 5: {
                printf("Thank you for using this program! \n");
                break;
            }

        }

    } while (choice != 5);

    return 0;
}





