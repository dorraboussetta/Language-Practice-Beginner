#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {
    int choice,c, num_per, num_alerts=0, personnel_type;
    personnel per[50];
    alert alerts[50];
    char login[15], password[15];

    printf("Enter the number of personnel: \n"); scanf("%d", &num_per);

    for (int index=0; index<num_per; index++) {
        per[index]=fill_personnel(index);

    }



    do {

        do {
    display_menu(0);
    scanf("%d", &c);

    if (c < 1 || c > 2) printf("Invalid choice! Please enter a number between 1 and 2.\n");

         } while (c < 1 || c > 2);

    switch (c) {

        case 1: {

            printf("Enter your login: \n"); fflush(stdin); gets(login);
            printf("Enter your password: \n"); fflush(stdin); gets(password);
            personnel_type=Connect_personnel(login,password,per,num_per);

            if (personnel_type==1) {
                do {

                    do {
                    display_menu(1);
                    scanf("%d", &choice);

                    if (choice < 1 || choice > 5) printf("Invalid choice! Please enter a number between 1 and 5.\n");

                     } while (choice < 1 || choice > 5);

                    switch (choice) {
                        case 1: {
                            num_alerts++;
                            alerts[num_alerts-1]=add_alert(alerts, num_alerts);

                            break;
                        }

                        case 2: {

                        display_alerts(alerts, num_alerts);

                            break;
                        }

                        case 3: {

                           modify_alert(alerts, num_alerts);

                            break;
                        }

                        case 4: {

                            if (num_alerts==0) printf("No alerts listed yet.\n");
                            else {
                                delete_alert(alerts, num_alerts);
                                num_alerts--;
                            }

                            break;
                        }

                        case 5: {

                            printf("Thank you for using this application! \n");
                            break;
                        }


                    }

                } while (choice != 5);}
            else if (personnel_type==2){
                    do {

                    do {
                    // Display the menu
                   display_menu(2);
                    scanf("%d", &choice);

                    // Validate input
                    if (choice < 1 || choice > 3) printf("Invalid choice! Please enter a number between 1 and 3.\n");

                     } while (choice < 1 || choice > 3);

                    // Execute based on user choice
                    switch (choice) {
                        case 1: {

                           display_alerts(alerts, num_alerts);

                            break;
                        }

                        case 2: {


                            alerts_percentage(alerts, num_alerts);

                            break;
                        }

                        case 3: {
                            printf("Thank you for using the application! \n");
                            break;
                        }

                    }

                } while (choice != 3);




            }

        else printf("No personnel with these credentials exists.\n");

        break;
        }
        case 2: {
            printf("Thank you for using this application.\n");
            break;

        }

    }

    } while (c!=2);

    return 0;
}

