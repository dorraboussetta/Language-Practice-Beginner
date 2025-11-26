#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program manages a collection of malfunctioning machines. Each machine has a
unique reference, a number of malfunctions, and a list of malfunction records.
Each malfunction is defined by a string reference and a repair status.

The application provides a menu that allows the user to add new machines while
ensuring unique references, display all stored machines, update the repair status
of a specific malfunction for a given machine, and remove any machine whose
malfunctions are all repaired.

The main educational objective of this program is to practice using pointers—
rather than numeric indices—to traverse arrays and to access structure fields
within those arrays.
*/

typedef struct {
    char mal_ref[20];
    int status;
} malfunction;

typedef struct {
    int unique_ref, num_mal;
    malfunction mal_list[20];

}machine;


int main()
{
 int choice, num_mch=0;
 machine mch[50];

    do {

        do {
        // Display the menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Add a machine to the end of the machine array\n");
        printf("2. Display the list of machines. \n");
        printf("3. Modify the status of a malfunction (from unrepaired to repaired) for a given machine by its reference.\n");
        printf("4. Remove all machines where the number of repaired malfunctions is equal to the total number of malfunctions.\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 5) printf("Invalid choice! Please enter a number between 1 and 7.\n");

         } while (choice < 1 || choice > 5);

        // Execute based on user choice
        switch (choice) {
            case 1: {
                int ref, no_machines=1;
                machine *p_mch=mch;

                if (num_mch>0) no_machines=0;

                printf("Enter the unique reference of the machine: \n"); scanf("%d", &ref);

                while (p_mch<(mch+num_mch) && p_mch->unique_ref!=ref) p_mch++;

                if (p_mch<(mch+num_mch) && no_machines==0) printf("A machine with this reference already exists.\n");
                else {
                    num_mch++;
                    p_mch->unique_ref=ref;
                    printf("Enter the number of malfuntions: \n"); scanf("%d", &p_mch->num_mal);

                    malfunction *p_mal;

                    for (p_mal=p_mch->mal_list; p_mal<p_mch->mal_list+ p_mch->num_mal  ; p_mal++) {
                        printf("Enter the reference of the malfuncion number %d: \n", (int)(p_mal - p_mch->mal_list)+1 ); fflush(stdin); gets(p_mal->mal_ref);
                        p_mal->status=0;

                    }


                }


                break;
            }

            case 2: {
                if (num_mch==0) {
                    printf("No machines to display.\n");
                    break;
                }


                machine *p_mch=mch;

                for (p_mch=mch; p_mch<mch+num_mch; p_mch++) {

                    printf("The unique reference of the machine %d: %d\n", (int)(p_mch-mch), p_mch->unique_ref);
                    printf("The number of malfunctions: %d\n", p_mch->num_mal);

                    malfunction *p_mal;

                     for (p_mal=p_mch->mal_list; p_mal<p_mch->mal_list+ p_mch->num_mal  ; p_mal++) {
                        printf("The reference of the malfunction number %d: %s \n", (int)(p_mal - p_mch->mal_list)+1, p_mal->mal_ref );
                        printf("The status of this malfunction is: %d\n", p_mal->status);

                    }



                }




                break;
            }

            case 3: {
                int ref;
                char malfunction_ref[20];

                printf("Enter the unique reference of the machine: \n"); scanf("%d", &ref);

                machine *p_mch=mch;

                while (p_mch<mch+num_mch && p_mch->unique_ref!=ref) p_mch++;
                if (p_mch==mch+num_mch) printf("No machine with this reference exists.\n");
                else {

                    printf("Enter the malfunction reference: \n"); fflush(stdin); gets(malfunction_ref);

                    malfunction *p_mal=p_mch->mal_list;
                    while (p_mal<p_mch->mal_list + p_mch->num_mal && strcmp(malfunction_ref, p_mal->mal_ref)!=0) p_mal++;
                    if (p_mal== p_mch->mal_list+ p_mch->num_mal) printf("No malfunction with this reference exists.\n");
                    else {

                        if (p_mal->status==1) printf("Already repaired.\n");
                        else {
                                p_mal->status=1;
                                printf("Status updated to repaired.\n");

                        }

                    }



                }


                break;
            }

            case 4: {
                machine *p_mch=mch, *p;
                int temp_num_mch=num_mch;


                while (p_mch<mch+num_mch) {

                        malfunction *p_mal=p_mch->mal_list;

                        while (p_mal<p_mch->mal_list+p_mch->num_mal && p_mal->status==1)  p_mal++;
                        if (p_mal==p_mch->mal_list+p_mch->num_mal){

                                if (p_mch!=mch+num_mch-1) {
                                    for (p=p_mch; p<mch+num_mch-1; p++) *p=*(p+1);

                                }
                                num_mch--;


                        }

                        p_mal=p_mch->mal_list;

                        while (p_mal<(p_mch->mal_list+p_mch->num_mal) && p_mal->status==1)  p_mal++;
                        if (p_mal<p_mch->mal_list+p_mch->num_mal) p_mch++;


                }
                if (temp_num_mch>num_mch) printf("Successfully deleted %d machines.\n", temp_num_mch-num_mch);


                break;
            }

            case 5: {

                printf("Thank you for using this program.\n");
                break;
            }

        }

    } while (choice != 5);

    return 0;
}


